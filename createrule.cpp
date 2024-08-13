#include "createrule.h"
#include "ui_createrule.h"
CreateRule::CreateRule(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateRule)
{
    ui->setupUi(this);
    m_MakeRule=new MakeRule(this);
    ui->tableWidget->setColumnCount(2);
    QStringList header;
    header<<"名称"<<"描述"<<"数据类型";
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setHorizontalHeaderLabels(header);
    connect(m_MakeRule,&MakeRule::CreateFinished,this,&CreateRule::AddRule);
    connect(this,&CreateRule::makerule_clear,m_MakeRule,&MakeRule::ui_clear);
}

void CreateRule::FlashTable()
{
    ui->tableWidget->setRowCount(this->Template.RuleNum);
    for(int i=0;i<Template.RuleNum;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(Template.m_Rule[i].Name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Template.m_Rule[i].Description));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(Template.m_Rule[i].GetType()));
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

void CreateRule::SolveDes(QString name, QString des)
{
    IsRevise=0;
    this->show();
    Template.Name=name;
    Template.Description=des;
}



void CreateRule::on_Create_triggered()
{
    m_MakeRule->show();
    emit makerule_clear();
}


void CreateRule::on_pushButton_released()
{
    emit AddRuleComplete(Template,IsRevise);
    this->close();
}

void CreateRule::ReceiveTemplate(RuleTemplate Temp)
{
    Template=Temp;
    IsRevise=1;
    FlashTable();
}



void CreateRule::on_Delete_triggered()
{
    int Index=ui->tableWidget->currentRow();
    Template.m_Rule.remove(Index);
    Template.RuleNum--;
    FlashTable();
}

