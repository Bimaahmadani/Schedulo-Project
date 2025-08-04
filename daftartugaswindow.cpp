#include "daftartugaswindow.h"
#include "ui_daftartugaswindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItem>
#include <QModelIndexList>
#include <QDate>
#include <QFileDialog>
#include <QTextStream>

DaftarTugasWindow::DaftarTugasWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DaftarTugasWindow),
    model(new QStandardItemModel(this))
{
    ui->setupUi(this);

    model->setHorizontalHeaderLabels(QStringList() << "Tugas" << "Mata Kuliah" << "Deadline" << "Keterangan" << "Status" << "Selesai");
    ui->tugasView->setModel(model);
    ui->tugasView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tugasView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tugasView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->searchButton, &QPushButton::clicked, this, &DaftarTugasWindow::cariTugas);
    connect(ui->deleteButton, &QPushButton::clicked, this, &DaftarTugasWindow::hapusBaris);
    connect(ui->returnButton, &QPushButton::clicked, this, &DaftarTugasWindow::kembaliKeMenu);

    connect(model, &QStandardItemModel::itemChanged, this, &DaftarTugasWindow::updateStatusSelesai);

    muatDataDariCSV();
}

DaftarTugasWindow::~DaftarTugasWindow()
{
    simpanDataKeCSV();
    delete ui;
}

void DaftarTugasWindow::muatDataDariCSV()
{
    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << "Tugas" << "Mata Kuliah" << "Deadline" << "Keterangan" << "Status" << "Selesai");

    QFile file("tugas.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() < 4) continue;

        QList<QStandardItem*> items;

        // Kolom 0-3: Tugas, Mata Kuliah, Deadline, Keterangan (editable seperti biasa)
        for (int i = 0; i < 4; ++i) {
            QStandardItem *item = new QStandardItem(fields[i]);
            item->setEditable(true);
            items.append(item);
        }

        // Kolom 5: Checkbox "Selesai"
        QString selesaiStr = fields.size() >= 6 ? fields[5] : "0";
        QStandardItem *selesaiItem = new QStandardItem();
        selesaiItem->setCheckable(true);
        selesaiItem->setCheckState(selesaiStr == "1" ? Qt::Checked : Qt::Unchecked);
        selesaiItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled); // ✅ checkbox aktif

        // Kolom 4: Status (tidak bisa diedit)
        QStandardItem *statusItem = hitungStatus(fields[2], selesaiItem->checkState() == Qt::Checked);
        statusItem->setFlags(statusItem->flags() & ~Qt::ItemIsEditable); // ✅ non-editable

        // Urutan: Tugas, Matkul, Deadline, Keterangan, Status, Selesai
        items.append(statusItem);
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

void DaftarTugasWindow::kembaliKeMenu()
{
    close();
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

QStandardItem* DaftarTugasWindow::hitungStatus(const QString& deadlineStr, bool selesai)
{
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

#include <QFileDialog>
#include <QTextStream>

void DaftarTugasWindow::on_downloadButton_clicked()
{
    QItemSelectionModel *selectionModel = ui->tugasView->selectionModel();
    QModelIndexList selectedIndexes = selectionModel->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Tidak Ada Tugas Dipilih", "Silakan pilih baris tugas terlebih dahulu.");
        return;
    }

    QString filePath = QFileDialog::getSaveFileName(this, "Simpan Tugas ke TXT", "", "Text Files (*.txt)");
    if (filePath.isEmpty())
        return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Gagal Menyimpan", "Tidak dapat membuka file untuk ditulis.");
        return;
    }

    QTextStream out(&file);

    // Header
    out << "==============================" << "\n";
    out << "       Daftar Tugas           " << "\n";
    out << "==============================" << "\n\n";

    for (const QModelIndex &index : selectedIndexes) {
        int row = index.row();
        QString tugas      = model->item(row, 0)->text();
        QString matkul     = model->item(row, 1)->text();
        QString deadline   = model->item(row, 2)->text();
        QString keterangan = model->item(row, 3)->text();
        QString status     = model->item(row, 4)->text();
        //QString selesai    = model->item(row, 5)->checkState() == Qt::Checked ? "Ya" : "Belum";

        out << "Tugas      : " << tugas << "\n";
        out << "Mata Kuliah: " << matkul << "\n";
        out << "Deadline   : " << deadline << "\n";
        out << "Keterangan : " << keterangan << "\n";
        out << "Status     : " << status << "\n";
        //out << "Selesai    : " << selesai << "\n";
        out << "------------------------------" << "\n";
    }
    QMessageBox::information(this, "Berhasil", "Data tugas berhasil disimpan ke file TXT.");
    file.close();

}
