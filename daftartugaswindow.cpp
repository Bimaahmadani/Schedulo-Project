#include "daftartugaswindow.h"
#include "ui_daftartugaswindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItem>
#include <QModelIndexList>

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
}

DaftarTugasWindow::~DaftarTugasWindow()
{
    simpanDataKeCSV();
    delete ui;
}

void DaftarTugasWindow::muatDataDariCSV()
{
    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << "Tugas" << "Mata Kuliah" << "Deadline" << "Keterangan");  // Atur ulang header

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
