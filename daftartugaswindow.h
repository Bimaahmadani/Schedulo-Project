// daftartugaswindow.h
#ifndef DAFTARTUGASWINDOW_H
#define DAFTARTUGASWINDOW_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class DaftarTugasWindow;
}

class DaftarTugasWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DaftarTugasWindow(QWidget *parent = nullptr);
    ~DaftarTugasWindow();
    void muatDataDariCSV();

private slots:
    void simpanDataKeCSV();
    void hapusBaris();
    void cariTugas();
    void kembaliKeMenu();
    void updateStatusSelesai(QStandardItem *item);
    void on_downloadButton_clicked();


private:
    Ui::DaftarTugasWindow *ui;
    QStandardItemModel *model;
    QString fileCSV = "tugas.csv";
    QStandardItem* hitungStatus(const QString& deadlineStr, bool selesai);

};

#endif // DAFTARTUGASWINDOW_H
