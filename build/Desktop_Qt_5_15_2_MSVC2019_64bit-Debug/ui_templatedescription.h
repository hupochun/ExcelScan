/********************************************************************************
** Form generated from reading UI file 'templatedescription.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATEDESCRIPTION_H
#define UI_TEMPLATEDESCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateDescription
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *TemplateDescription)
    {
        if (TemplateDescription->objectName().isEmpty())
            TemplateDescription->setObjectName(QString::fromUtf8("TemplateDescription"));
        TemplateDescription->resize(400, 300);
        gridLayout_3 = new QGridLayout(TemplateDescription);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(93, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(93, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        widget_2 = new QWidget(TemplateDescription);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);


        gridLayout_3->addWidget(widget_2, 2, 1, 1, 1);

        widget = new QWidget(TemplateDescription);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget, 1, 1, 1, 1);


        retranslateUi(TemplateDescription);

        QMetaObject::connectSlotsByName(TemplateDescription);
    } // setupUi

    void retranslateUi(QWidget *TemplateDescription)
    {
        TemplateDescription->setWindowTitle(QCoreApplication::translate("TemplateDescription", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("TemplateDescription", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("TemplateDescription", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("TemplateDescription", "\346\217\217\350\277\260", nullptr));
        label->setText(QCoreApplication::translate("TemplateDescription", "\345\220\215\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TemplateDescription: public Ui_TemplateDescription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATEDESCRIPTION_H
