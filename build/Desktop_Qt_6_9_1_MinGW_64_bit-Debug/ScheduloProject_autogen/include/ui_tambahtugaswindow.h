/********************************************************************************
** Form generated from reading UI file 'tambahtugaswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAMBAHTUGASWINDOW_H
#define UI_TAMBAHTUGASWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TambahTugasWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *returnButton;
    QLabel *label_5;

    void setupUi(QDialog *TambahTugasWindow)
    {
        if (TambahTugasWindow->objectName().isEmpty())
            TambahTugasWindow->setObjectName("TambahTugasWindow");
        TambahTugasWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TambahTugasWindow->sizePolicy().hasHeightForWidth());
        TambahTugasWindow->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(TambahTugasWindow);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 80, 801, 431));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(30, 0, 30, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setWordWrap(false);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(lineEdit);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(16777215, 40));
        label_2->setFont(font);
        label_2->setWordWrap(false);

        verticalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(lineEdit_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(16777215, 40));
        label_3->setFont(font);
        label_3->setWordWrap(false);

        verticalLayout->addWidget(label_3);

        dateEdit = new QDateEdit(verticalLayoutWidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setMinimumSize(QSize(0, 35));

        verticalLayout->addWidget(dateEdit);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMaximumSize(QSize(16777215, 40));
        label_4->setFont(font);
        label_4->setWordWrap(false);

        verticalLayout->addWidget(label_4);

        plainTextEdit = new QPlainTextEdit(verticalLayoutWidget);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayoutWidget = new QWidget(TambahTugasWindow);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(590, 520, 179, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName("addButton");

        horizontalLayout->addWidget(addButton);

        returnButton = new QPushButton(horizontalLayoutWidget);
        returnButton->setObjectName("returnButton");

        horizontalLayout->addWidget(returnButton);

        label_5 = new QLabel(TambahTugasWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 10, 801, 61));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(TambahTugasWindow);

        QMetaObject::connectSlotsByName(TambahTugasWindow);
    } // setupUi

    void retranslateUi(QDialog *TambahTugasWindow)
    {
        TambahTugasWindow->setWindowTitle(QCoreApplication::translate("TambahTugasWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TambahTugasWindow", "Nama Tugas", nullptr));
        label_2->setText(QCoreApplication::translate("TambahTugasWindow", "Mata Kuliah", nullptr));
        label_3->setText(QCoreApplication::translate("TambahTugasWindow", "Deadline", nullptr));
        label_4->setText(QCoreApplication::translate("TambahTugasWindow", "Keterangan", nullptr));
        addButton->setText(QCoreApplication::translate("TambahTugasWindow", "Tambah", nullptr));
        returnButton->setText(QCoreApplication::translate("TambahTugasWindow", "Kembali", nullptr));
        label_5->setText(QCoreApplication::translate("TambahTugasWindow", "Tambah Tugas", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TambahTugasWindow: public Ui_TambahTugasWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAMBAHTUGASWINDOW_H
