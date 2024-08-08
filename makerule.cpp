#include "makerule.h"
#include "ui_makerule.h"
#include <QListView>
MakeRule::MakeRule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MakeRule)
{
    ui->setupUi(this);
    ui->comboBox->addItem("字符串类型");
    ui->comboBox->addItem("是否");
    ui->comboBox->addItem("年月日");
    ui->comboBox->addItem("年月日时分秒");
    ui->comboBox->addItem("数字");
    ui->comboBox->addItem("小数");
    ui->comboBox->addItem("百分比");

    ui->comboBox_2->addItem("X存在");
    ui->comboBox_2->addItem("X不存在");
    ui->comboBox_2->addItem("存在XXXX中的N个");
    ui->comboBox_2->addItem("不存在XXXX中的任N个");

    //字符串规则
    ui->comboBox_2->addItem("X等于Y");
    ui->comboBox_2->addItem("X不等于Y");
    ui->comboBox_2->addItem("X内容为空");
    ui->comboBox_2->addItem("X内容不为空");
    ui->comboBox_2->addItem("X包含Y");
    ui->comboBox_2->addItem("X不包含Y");
    ui->comboBox_2->addItem("X是XXXX中的1个");
    ui->comboBox_2->addItem("X不是XXXX中的1个");
}


MakeRule::~MakeRule()
{
    delete ui;
}

void MakeRule::on_pushButton_2_released()
{
    this->close();
}


void MakeRule::on_pushButton_released()
{
    Rule temp(ui->comboBox->currentIndex(),ui->comboBox_2->currentIndex(),ui->lineEdit_3->text(),ui->lineEdit_4->text());
    temp.Name=ui->lineEdit->text();
    temp.Description=ui->lineEdit_2->text();
    emit(CreateFinished(temp));
    this->close();
}


void MakeRule::on_comboBox_activated(int index)
{
    ui->comboBox_2->clear();
    //存在规则
    ui->comboBox_2->addItem("X存在");
    ui->comboBox_2->addItem("X不存在");
    ui->comboBox_2->addItem("存在XXXX中的N个");
    ui->comboBox_2->addItem("不存在XXXX中的任N个");

    //字符串规则
    ui->comboBox_2->addItem("X等于Y");
    ui->comboBox_2->addItem("X不等于Y");
    ui->comboBox_2->addItem("X内容为空");
    ui->comboBox_2->addItem("X内容不为空");
    ui->comboBox_2->addItem("X包含Y");
    ui->comboBox_2->addItem("X不包含Y");
    ui->comboBox_2->addItem("X是XXXX中的1个");
    ui->comboBox_2->addItem("X不是XXXX中的1个");

    //数字规则
    ui->comboBox_2->addItem("X小于Y");
    ui->comboBox_2->addItem("X小于等于Y");
    ui->comboBox_2->addItem("X大于Y");
    ui->comboBox_2->addItem("X大于等于Y");
    ui->comboBox_2->addItem("X等于Y");
    ui->comboBox_2->addItem("X不等于Y");
    ui->comboBox_2->addItem("X在Y和Z时间范围内");
    ui->comboBox_2->addItem("X是XXXX中的1个");
    ui->comboBox_2->addItem("X不是XXXX中的1个");

    //时间规则
    ui->comboBox_2->addItem("X早于Y");
    ui->comboBox_2->addItem("X早于等于Y");
    ui->comboBox_2->addItem("X晚于Y");
    ui->comboBox_2->addItem("X晚于等于Y");
    ui->comboBox_2->addItem("X和Y时间相同");
    ui->comboBox_2->addItem("X在Y和Z时间范围内");
    ui->comboBox_2->addItem("X是XXXX中的1个");
    ui->comboBox_2->addItem("X不是XXXX中的1个");

    QListView* view = qobject_cast<QListView*>(ui->comboBox_2->view());
    if(index==0)
    {
        for(int i=12;i<29;i++)
        view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==1)
    {
        for(int i=4;i<29;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==2)
    {
        for(int i=4;i<21;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==3)
    {
        for(int i=4;i<21;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==4)
    {
        for(int i=4;i<21;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==5)
    {
        for(int i=4;i<12;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
        for(int i=21;i<29;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==6)
    {
        for(int i=4;i<12;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
        for(int i=21;i<29;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
    if(index==7)
    {
        for(int i=4;i<12;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
        for(int i=21;i<29;i++)
            view->setRowHidden(i, true);//隐藏为TRUE，显示为false
    }
}

