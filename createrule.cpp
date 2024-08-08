#include "createrule.h"
#include "ui_createrule.h"
CreateRule::CreateRule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateRule)
{
    ui->setupUi(this);
    m_MakeRule=new MakeRule;
    ui->tableWidget->setColumnCount(2);
    QStringList header;
    header<<"名称"<<"描述";
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setHorizontalHeaderLabels(header);
    connect(m_MakeRule,&MakeRule::CreateFinished,this,&CreateRule::AddRule);

}

void CreateRule::FlashTable()
{
    ui->tableWidget->setRowCount(this->Template.RuleNum);
    for(int i=0;i<Template.RuleNum;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(Template.m_Rule[i].Name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Template.m_Rule[i].Description));
    }
}

CreateRule::~CreateRule()
{
    delete ui;
    m_MakeRule->deleteLater();
}

void CreateRule::AddRule(Rule temp)
{
    this->Template.m_Rule.append(temp);
    this->Template.RuleNum++;
    FlashTable();
}

void CreateRule::on_Create_triggered()
{
    m_MakeRule->show();
}

