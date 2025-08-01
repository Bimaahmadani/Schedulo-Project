/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addView;
    QPushButton *readView;
    QPushButton *quitButton;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName("MenuWindow");
        MenuWindow->resize(600, 400);
        centralwidget = new QWidget(MenuWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(120, 90, 361, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addView = new QPushButton(verticalLayoutWidget);
        addView->setObjectName("addView");
        addView->setMinimumSize(QSize(0, 40));
        addView->setMaximumSize(QSize(16777215, 32));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Sans")});
        font.setPointSize(10);
        font.setBold(true);
        addView->setFont(font);

        verticalLayout->addWidget(addView);

        readView = new QPushButton(verticalLayoutWidget);
        readView->setObjectName("readView");
        readView->setEnabled(true);
        readView->setMinimumSize(QSize(0, 40));
        readView->setFont(font);

        verticalLayout->addWidget(readView);

        quitButton = new QPushButton(verticalLayoutWidget);
        quitButton->setObjectName("quitButton");
        quitButton->setMinimumSize(QSize(0, 40));
        quitButton->setFont(font);

        verticalLayout->addWidget(quitButton);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 19, 601, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Montserrat Ace")});
        font1.setPointSize(30);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MenuWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MenuWindow);
        statusbar->setObjectName("statusbar");
        MenuWindow->setStatusBar(statusbar);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QCoreApplication::translate("MenuWindow", "MenuWindow", nullptr));
        addView->setText(QCoreApplication::translate("MenuWindow", "Tambah Tugas", nullptr));
        readView->setText(QCoreApplication::translate("MenuWindow", "Daftar Tugas ", nullptr));
        quitButton->setText(QCoreApplication::translate("MenuWindow", "Keluar", nullptr));
        label->setText(QCoreApplication::translate("MenuWindow", "Schedulo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
