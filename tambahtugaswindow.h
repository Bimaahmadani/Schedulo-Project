#ifndef TAMBAHTUGASWINDOW_H
#define TAMBAHTUGASWINDOW_H

#include <QDialog>

namespace Ui {
class TambahTugasWindow;
}

class TambahTugasWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TambahTugasWindow(QWidget *parent = nullptr);
    ~TambahTugasWindow();

signals:
    void tugasDitambahkan();

private slots:
    void on_addButton_clicked();
    void on_returnButton_clicked();

private:
    Ui::TambahTugasWindow *ui;
    void simpanKeCSV(const QString &tugas, const QString &matkul, const QDate &deadline, const QString &keterangan);
};

#endif // TAMBAHTUGASWINDOW_H
