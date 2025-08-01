#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "tambahtugaswindow.h"
#include "daftartugaswindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void on_addView_clicked();
    void on_readView_clicked();
    void on_quitButton_clicked();

private:
    Ui::MenuWindow *ui;
    TambahTugasWindow *tambahTugasWindow;
    DaftarTugasWindow *daftarTugasWindow;
};

#endif // MENUWINDOW_H
