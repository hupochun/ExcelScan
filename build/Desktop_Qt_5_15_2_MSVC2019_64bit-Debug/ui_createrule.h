/********************************************************************************
** Form generated from reading UI file 'createrule.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATERULE_H
#define UI_CREATERULE_H

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

class Ui_CreateRule
{
public:
    QAction *Create;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateRule)
    {
        if (CreateRule->objectName().isEmpty())
            CreateRule->setObjectName(QString::fromUtf8("CreateRule"));
        CreateRule->resize(800, 600);
        Create = new QAction(CreateRule);
        Create->setObjectName(QString::fromUtf8("Create"));
        centralwidget = new QWidget(CreateRule);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        CreateRule->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateRule);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CreateRule->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateRule);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateRule->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Create);

        retranslateUi(CreateRule);

        QMetaObject::connectSlotsByName(CreateRule);
    } // setupUi

    void retranslateUi(QMainWindow *CreateRule)
    {
        CreateRule->setWindowTitle(QCoreApplication::translate("CreateRule", "MainWindow", nullptr));
        Create->setText(QCoreApplication::translate("CreateRule", "\345\210\233\345\273\272", nullptr));
        menu->setTitle(QCoreApplication::translate("CreateRule", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateRule: public Ui_CreateRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERULE_H
