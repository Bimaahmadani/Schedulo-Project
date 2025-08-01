#include "daftartugaswindow.h"
#include "ui_daftartugaswindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItem>
#include <QModelIndexList>
#include <QDate>


DaftarTugasWindow::DaftarTugasWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DaftarTugasWindow),
    model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    model->setHorizontalHeaderLabels(QStringList() << "Tugas" << "Mata Kuliah" << "Deadline" << "Keterangan");
    ui->tugasView->setModel(model);
    ui->tugasView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tugasView->setEditTriggers(QAbstractItemView::DoubleClicked);

    connect(ui->searchButton, &QPushButton::clicked, this, &DaftarTugasWindow::cariTugas);
    connect(ui->deleteButton, &QPushButton::clicked, this, &DaftarTugasWindow::hapusBaris);
    connect(ui->returnButton, &QPushButton::clicked, this, &DaftarTugasWindow::kembaliKeMenu);

    muatDataDariCSV();

    connect(model, &QStandardItemModel::itemChanged, this, &DaftarTugasWindow::updateStatusSelesai);

}

void DaftarTugasWindow::updateStatusSelesai(QStandardItem *item)
{
    if (item->column() == 5) { // kolom "Selesai"
        int row = item->row();
        QString deadline = model->item(row, 2)->text();
        bool isSelesai = item->checkState() == Qt::Checked;
        QStandardItem* statusItem = hitungStatus(deadline, isSelesai);
        model->setItem(row, 4, statusItem);
        simpanDataKeCSV();
    }
}


DaftarTugasWindow::~DaftarTugasWindow()
{
    simpanDataKeCSV();
    delete ui;
}

void DaftarTugasWindow::muatDataDariCSV()
{
    model->clear();
    /*model->setHorizontalHeaderLabels(QStringList() << "Tugas" << "Mata Kuliah" << "Deadline" << "Keterangan"); */ // Atur ulang header
    model->setHorizontalHeaderLabels(QStringList() << "Tugas" << "Mata Kuliah" << "Deadline" << "Keterangan" << "Status" << "Selesai");

    QFile file("tugas.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        QList<QStandardItem*> items;
        for (const QString &field : fields) {
            items.append(new QStandardItem(field));
        }
        model->appendRow(items);
    }

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() < 4) continue; // skip baris rusak

        QList<QStandardItem*> items;
        for (int i = 0; i < 4; ++i) {
            items.append(new QStandardItem(fields[i]));
        }

        // Cek status selesai
        QString selesaiStr = fields.size() >= 6 ? fields[5] : "0";  // default belum selesai
        QStandardItem *selesaiItem = new QStandardItem();
        selesaiItem->setCheckable(true);
        selesaiItem->setCheckState(selesaiStr == "1" ? Qt::Checked : Qt::Unchecked);
        items.append(hitungStatus(fields[2], selesaiItem->checkState() == Qt::Checked));
        items.append(selesaiItem);

        model->appendRow(items);
    }

    file.close();
}

void DaftarTugasWindow::simpanDataKeCSV()
{
    QFile file("tugas.csv");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList fields;
        for (int col = 0; col < model->columnCount(); ++col) {
            fields << model->item(row, col)->text();
        }
        out << fields.join(",") << "\n";
    }

    for (int row = 0; row < model->rowCount(); ++row) {
        QStringList fields;
        for (int col = 0; col < 4; ++col) {
            fields << model->item(row, col)->text();
        }
        fields << model->item(row, 4)->text(); // Status
        fields << (model->item(row, 5)->checkState() == Qt::Checked ? "1" : "0"); // Selesai
        out << fields.join(",") << "\n";
    }

    file.close();
}

void DaftarTugasWindow::hapusBaris()
{
    QModelIndexList selected = ui->tugasView->selectionModel()->selectedRows();
    for (const QModelIndex &index : selected) {
        model->removeRow(index.row());
    }
    simpanDataKeCSV();
}

void DaftarTugasWindow::cariTugas()
{
    QString keyword = ui->searchEdit->text().trimmed();
    for (int row = 0; row < model->rowCount(); ++row) {
        bool match = false;
        for (int col = 0; col < model->columnCount(); ++col) {
            if (model->item(row, col)->text().contains(keyword, Qt::CaseInsensitive)) {
                match = true;
                break;
            }
        }
        ui->tugasView->setRowHidden(row, !match);
    }
}

QStandardItem* DaftarTugasWindow::hitungStatus(const QString& deadlineStr, bool selesai) {
    QDate deadline = QDate::fromString(deadlineStr, "dd-MM-yyyy");
    QDate today = QDate::currentDate();

    QString status;
    if (selesai) {
        status = "Selesai";
    } else if (today > deadline) {
        status = "Telat";
    } else if (today.daysTo(deadline) <= 1) {
        status = "Urgent";
    } else {
        status = "Belum Selesai";
    }

    return new QStandardItem(status);
}


void DaftarTugasWindow::kembaliKeMenu()
{
    close();
}
