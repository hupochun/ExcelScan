/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Create;
    QAction *Copy;
    QAction *Delete;
    QAction *Export;
    QAction *Import;
    QAction *Rename;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        Create = new QAction(MainWindow);
        Create->setObjectName(QString::fromUtf8("Create"));
        Copy = new QAction(MainWindow);
        Copy->setObjectName(QString::fromUtf8("Copy"));
        Delete = new QAction(MainWindow);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Export = new QAction(MainWindow);
        Export->setObjectName(QString::fromUtf8("Export"));
        Import = new QAction(MainWindow);
        Import->setObjectName(QString::fromUtf8("Import"));
        Rename = new QAction(MainWindow);
        Rename->setObjectName(QString::fromUtf8("Rename"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Create);
        menu->addAction(Copy);
        menu->addAction(Delete);
        menu->addAction(Export);
        menu->addAction(Import);
        menu->addAction(Rename);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Create->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272", nullptr));
        Copy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        Export->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
        Import->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
        Rename->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\221\275\345\220\215", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
