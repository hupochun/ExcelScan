/********************************************************************************
** Form generated from reading UI file 'rename.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAME_H
#define UI_RENAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rename
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QSpacerItem *verticalSpacer;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Rename)
    {
        if (Rename->objectName().isEmpty())
            Rename->setObjectName(QString::fromUtf8("Rename"));
        Rename->resize(400, 300);
        gridLayout = new QGridLayout(Rename);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(Rename);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 0, 0, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(73, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_5->addWidget(widget_3, 1, 0, 1, 1);

        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        pushButton = new QPushButton(widget_4);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_4->addWidget(pushButton, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(126, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 2, 1, 1);


        gridLayout_5->addWidget(widget_4, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 57, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 3, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Rename);

        QMetaObject::connectSlotsByName(Rename);
    } // setupUi

    void retranslateUi(QDialog *Rename)
    {
        Rename->setWindowTitle(QCoreApplication::translate("Rename", "\351\207\215\345\221\275\345\220\215", nullptr));
        label->setText(QCoreApplication::translate("Rename", "\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("Rename", "\346\217\217\350\277\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Rename", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rename: public Ui_Rename {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAME_H
