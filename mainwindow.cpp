#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createrule.h"
#include <QFileDialog>
#include <QDebug>
#include <QThreadPool>
#include "analysisjson.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_TemplateDescription=new TemplateDescription(this);
    m_CreateRule=new CreateRule(this);

    QStringList header;
    header<<"名称"<<"描述";
    ui->tableWidget->setRowCount(this->m_Template.size());
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setHorizontalHeaderLabels(header);
    connect(m_CreateRule,&CreateRule::AddRuleComplete,this,&MainWindow::AddTemplateFinished);
    connect(m_TemplateDescription,&TemplateDescription::TemplateDescriFinished,m_CreateRule,&CreateRule::SolveDes);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::FlashTable()
{
    ui->tableWidget->setRowCount(this->m_Template.size());
    for(int i=0;i<m_Template.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(m_Template[i].Name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(m_Template[i].Description));
    }
}


void MainWindow::on_Create_triggered()
{
    //m_CreateRule->show();
    m_TemplateDescription->show();
}

void MainWindow::AddTemplateFinished(RuleTemplate temp)
{
    m_Template.append(temp);
    FlashTable();
}


void MainWindow::on_action_triggered()
{
    TemplateIndex=ui->tableWidget->currentIndex().row();
    QXlsx::Document Doc(FileDir);
    //m_thread=new MyCheckThread(&Doc,m_Template,TemplateIndex,this);
    //connect(m_thread,&MyCheckThread::CheckFinished,this,&MainWindow::ShowErro);
    //QThreadPool::globalInstance()->start(m_thread);
    for(int i=0;i<m_Template[TemplateIndex].m_Rule.size();i++)
    {
        m_Template[TemplateIndex].m_Rule[i].CheckRule(Doc);
    }
    ShowErro();
}


void MainWindow::on_action_Excel_triggered()
{
    FileDir = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "", // 起始目录
                                                    tr("Excel Files (*.xlsx);;")); // 文件过滤器

}

void MainWindow::ShowErro()
{
    qDebug()<<m_Template[TemplateIndex].m_Rule[0].ErrMsg[0].ErrCol;
    qDebug()<<m_Template[TemplateIndex].m_Rule[0].ErrMsg[0].ErrRow;
}


void MainWindow::on_Export_triggered()
{
    TemplateIndex=ui->tableWidget->currentIndex().row();
    AnalysisJson::saveRuleTemplateToJson(m_Template[TemplateIndex],"./"+m_Template[TemplateIndex].Name+".json");
}


void MainWindow::on_Import_triggered()
{
    QStringList file_name = QFileDialog::getOpenFileNames(this,"导入",".","*.json");
    for(int i=0;i<file_name.length();i++)
    {
        m_Template.append(AnalysisJson::loadRuleTemplateFromJson(file_name[i]));
    }
    FlashTable();

}


void MainWindow::on_Delete_triggered()
{
    TemplateIndex=ui->tableWidget->currentIndex().row();
    m_Template.remove(TemplateIndex);
    FlashTable();
}

