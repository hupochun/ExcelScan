#include "rename.h"
#include "ui_rename.h"
#include <QMessageBox>
Rename::Rename(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Rename)
{
    ui->setupUi(this);
}

Rename::~Rename()
{
    delete ui;
}

void Rename::on_pushButton_released()
{
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty())
    {
        QMessageBox::about(this,"提示","名称或描述不能为空");
    }
    emit RenameComplete(ui->lineEdit->text(),ui->lineEdit_2->text());
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    this->close();
}

