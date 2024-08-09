#include "templatedescription.h"
#include "ui_templatedescription.h"
#include <QMessageBox>
TemplateDescription::TemplateDescription(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TemplateDescription)
{
    ui->setupUi(this);
}

TemplateDescription::~TemplateDescription()
{
    delete ui;
}

void TemplateDescription::on_pushButton_released()
{
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::about(this,"提示","模板名称和描述不能为空");
        return;
    }
    emit TemplateDescriFinished(ui->lineEdit->text(),ui->lineEdit_2->text());
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    this->close();
}


void TemplateDescription::on_pushButton_2_released()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    this->close();
}

