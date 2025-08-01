#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MenuWindow)
    , tambahTugasWindow(new TambahTugasWindow(this))
    , daftarTugasWindow(new DaftarTugasWindow(this))
{
    ui->setupUi(this);

    // Tombol menu
    connect(ui->addView, &QPushButton::clicked, this, &MenuWindow::on_addView_clicked);
    connect(ui->readView, &QPushButton::clicked, this, &MenuWindow::on_readView_clicked);
    connect(ui->quitButton, &QPushButton::clicked, this, &MenuWindow::on_quitButton_clicked);

    // KONEKSI PENTING!
    connect(tambahTugasWindow, &TambahTugasWindow::tugasDitambahkan,
            daftarTugasWindow, &DaftarTugasWindow::muatDataDariCSV);
}
MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_addView_clicked()
{
    tambahTugasWindow->exec();
}

void MenuWindow::on_readView_clicked()
{
    daftarTugasWindow->show();
}

void MenuWindow::on_quitButton_clicked()
{
    close();
}

