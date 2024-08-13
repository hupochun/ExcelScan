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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateRule
{
public:
    QAction *Create;
    QAction *Delete;
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateRule)
    {
        if (CreateRule->objectName().isEmpty())
            CreateRule->setObjectName(QString::fromUtf8("CreateRule"));
        CreateRule->resize(426, 545);
        Create = new QAction(CreateRule);
        Create->setObjectName(QString::fromUtf8("Create"));
        Delete = new QAction(CreateRule);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        centralwidget = new QWidget(CreateRule);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setGridStyle(Qt::SolidLine);

        gridLayout_4->addWidget(tableWidget, 1, 0, 1, 4);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(122, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(121, 35, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_4->addWidget(widget_3, 2, 1, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_4->addWidget(widget_2, 2, 2, 1, 1);

        CreateRule->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateRule);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 426, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CreateRule->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateRule);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateRule->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Create);
        menu->addAction(Delete);

        retranslateUi(CreateRule);

        QMetaObject::connectSlotsByName(CreateRule);
    } // setupUi

    void retranslateUi(QMainWindow *CreateRule)
    {
        CreateRule->setWindowTitle(QCoreApplication::translate("CreateRule", "MainWindow", nullptr));
        Create->setText(QCoreApplication::translate("CreateRule", "\345\210\233\345\273\272", nullptr));
        Delete->setText(QCoreApplication::translate("CreateRule", "\345\210\240\351\231\244", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateRule", "\344\277\235\345\255\230", nullptr));
        menu->setTitle(QCoreApplication::translate("CreateRule", "\351\200\211\351\241\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateRule: public Ui_CreateRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATERULE_H
