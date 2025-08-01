#include "tambahtugaswindow.h"
#include "ui_tambahtugaswindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

TambahTugasWindow::TambahTugasWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TambahTugasWindow)
{
    ui->setupUi(this);
}

TambahTugasWindow::~TambahTugasWindow()
{
    delete ui;
}

void TambahTugasWindow::on_addButton_clicked()
{
    QString tugas = ui->lineEdit->text();
    QString matkul = ui->lineEdit_2->text();
    QDate deadline = ui->dateEdit->date();
    QString keterangan = ui->plainTextEdit->toPlainText();

    if (tugas.isEmpty() || matkul.isEmpty()) {
        QMessageBox::warning(this, "Input Gagal", "Harap isi semua kolom!");
        return;
    }

    simpanKeCSV(tugas, matkul, deadline, keterangan);
    emit tugasDitambahkan();
    QMessageBox::information(this, "Tersimpan", "Tugas berhasil ditambahkan!");

    // Kosongkan form setelah data disimpan
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->plainTextEdit->clear();

    close();  // Tutup window setelah menambahkan tugas
}

void TambahTugasWindow::simpanKeCSV(const QString &tugas, const QString &matkul, const QDate &deadline, const QString &keterangan)
{
    QFile file("tugas.csv");
    bool fileBaru = !file.exists();

    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        if (fileBaru) {
            out << "Tugas,Mata Kuliah,Deadline,Keterangan\n";
        }

        QString keteranganBersih = keterangan;
        keteranganBersih.replace("\n", " ");
        out << tugas << "," << matkul << "," << deadline.toString("yyyy-MM-dd") << "," << keteranganBersih << "\n";

        file.close();
    }
}

void TambahTugasWindow::on_returnButton_clicked()
{
    this->close();
}
