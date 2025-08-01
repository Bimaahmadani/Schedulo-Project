/********************************************************************************
** Form generated from reading UI file 'daftartugaswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAFTARTUGASWINDOW_H
#define UI_DAFTARTUGASWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_DaftarTugasWindow
{
public:
    QTableView *tugasView;
    QLabel *label;
    QPushButton *returnButton;
    QLineEdit *searchEdit;
    QPushButton *searchButton;
    QPushButton *deleteButton;

    void setupUi(QDialog *DaftarTugasWindow)
    {
        if (DaftarTugasWindow->objectName().isEmpty())
            DaftarTugasWindow->setObjectName("DaftarTugasWindow");
        DaftarTugasWindow->resize(800, 600);
        tugasView = new QTableView(DaftarTugasWindow);
        tugasView->setObjectName("tugasView");
        tugasView->setGeometry(QRect(40, 140, 721, 381));
        label = new QLabel(DaftarTugasWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 20, 801, 51));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        returnButton = new QPushButton(DaftarTugasWindow);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(580, 540, 177, 29));
        searchEdit = new QLineEdit(DaftarTugasWindow);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setGeometry(QRect(40, 90, 250, 30));
        searchButton = new QPushButton(DaftarTugasWindow);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(300, 90, 80, 30));
        deleteButton = new QPushButton(DaftarTugasWindow);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(400, 90, 90, 30));

        retranslateUi(DaftarTugasWindow);

        QMetaObject::connectSlotsByName(DaftarTugasWindow);
    } // setupUi

    void retranslateUi(QDialog *DaftarTugasWindow)
    {
        DaftarTugasWindow->setWindowTitle(QCoreApplication::translate("DaftarTugasWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DaftarTugasWindow", "Daftar Tugas", nullptr));
        returnButton->setText(QCoreApplication::translate("DaftarTugasWindow", "Kembali", nullptr));
        searchButton->setText(QCoreApplication::translate("DaftarTugasWindow", "Search", nullptr));
        deleteButton->setText(QCoreApplication::translate("DaftarTugasWindow", "Hapus", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DaftarTugasWindow: public Ui_DaftarTugasWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAFTARTUGASWINDOW_H
