#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createrule.h"
#include <QFileDialog>
#include <QDebug>
#include <QThreadPool>
#include "analysisjson.h"
#include <QMessageBox>
#include <QProcess>
#include <QRandomGenerator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_TemplateDescription=new TemplateDescription(this);
    m_CreateRule=new CreateRule(this);
    m_ReName=new Rename(this);
    QStringList header;
    header<<"名称"<<"描述"<<"规则数量";
    ui->tableWidget->setRowCount(this->m_Template.size());
    ui->tableWidget->setColumnCount(header.size());
    ui->tableWidget->setHorizontalHeaderLabels(header);
    connect(m_CreateRule,&CreateRule::AddRuleComplete,this,&MainWindow::AddTemplateFinished);
    connect(m_TemplateDescription,&TemplateDescription::TemplateDescriFinished,m_CreateRule,&CreateRule::SolveDes);
    connect(this,&MainWindow::EditTemplate,m_CreateRule,&CreateRule::ReceiveTemplate);
    connect(m_ReName,&Rename::RenameComplete,this,&MainWindow::ReNameComplete);
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
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(m_Template[i].RuleNum)));
    }
}

QColor MainWindow::randomQtColor()
{
    static const QVector<QColor> colors = {
        Qt::cyan, Qt::yellow, Qt::lightGray, Qt::magenta
    };
    QRandomGenerator rng(QRandomGenerator::global()->bounded(1, 1000000));
    int index = rng.bounded(colors.size());  // 随机选择一个颜色索引
    return colors[index];  // 返回随机颜色
}

void MainWindow::updateCellColor(QXlsx::Document &xlsx, const QString &cell, const QColor &color)
{
    QVariant value = xlsx.read(cell);

    // 创建新的格式
    QXlsx::Format format;
    format.setPatternBackgroundColor(color);

    // 重新写入数据和格式
    xlsx.write(cell, value, format);
}


void MainWindow::on_Create_triggered()
{
    //m_CreateRule->show();
    m_TemplateDescription->show();
}

void MainWindow::AddTemplateFinished(RuleTemplate temp,bool isRevise)
{
    if(!isRevise)
    {
        m_Template.append(temp);
    }
    else
    {
        m_Template[TemplateIndex]=temp;
    }
    FlashTable();
}


void MainWindow::on_action_triggered()
{
    // ui->tableWidget->selectionModel()->selectedRows()
    if(FileDir.isEmpty())
    {
        QMessageBox::about(this,"提示","没有选择要处理的Excel文件");
        return;
    }
    QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();

    // 使用QSet来避免重复的行索引
    QSet<int> selectedRows;
    for (QTableWidgetItem *item : selectedItems) {
        selectedRows.insert(item->row());
    }
    QXlsx::Document Doc(FileDir);
    //m_thread=new MyCheckThread(&Doc,m_Template,TemplateIndex,this);
    //connect(m_thread,&MyCheckThread::CheckFinished,this,&MainWindow::ShowErro);
    //QThreadPool::globalInstance()->start(m_thread);
    for(int TemplateIndex:selectedRows)
        for(int i=0;i<m_Template[TemplateIndex].m_Rule.size();i++)
        {
            m_Template[TemplateIndex].m_Rule[i].CheckRule(Doc);
        }
//输出检查结果
    for(int i=0;i<m_Template.size();i++)
    {
        for(int j=0;j<m_Template[i].m_Rule.size();j++)
        {
            QColor randomcolor=randomQtColor();
            for(int k=0;k<m_Template[i].m_Rule[j].ErrMsg.size();k++)
            {
                updateCellColor(Doc,QString("%1%2").arg(m_Template[i].m_Rule[j].ErrMsg[k].ErrCol).arg(m_Template[i].m_Rule[j].ErrMsg[k].ErrRow),randomcolor);
            }
        }
    }
    QString directory = QFileDialog::getExistingDirectory(
        nullptr,            // 父窗口
        "选择文件夹",       // 对话框标题
        QString(),          // 初始目录（留空表示默认目录）
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks  // 只显示文件夹，不解析符号链接
        );
    Doc.saveAs(directory+"/"+"output.xlsx");
}


void MainWindow::on_action_Excel_triggered()
{
    FileDir = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"),
                                                    "", // 起始目录
                                                    tr("Excel Files (*.csv);;")); // 文件过滤器
    if(FileDir.isEmpty())
        return;
    QFileInfo fileInfo(FileDir);
    QString directory = fileInfo.absolutePath();
    QString fileName = fileInfo.fileName();
    QStringList parts=fileName.split('.');
    QProcess* convert=new QProcess(this);
    QString program="csv2xlsx.exe";
    QStringList argu;
    argu.append(FileDir);
    FileDir=directory+'/'+parts[0]+".xlsx";
    convert->start(program,argu);
    convert->terminate(); // 或 process->kill();
    if (!convert->waitForFinished(2000)) { // 等待最多 2 秒
        qWarning() << "Process did not terminate in time.";
    }
    delete convert;

}



void MainWindow::on_Export_triggered()
{
    TemplateIndex=ui->tableWidget->currentIndex().row();
    QString directory = QFileDialog::getExistingDirectory(
        nullptr,            // 父窗口
        "选择文件夹",       // 对话框标题
        QString(),          // 初始目录（留空表示默认目录）
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks  // 只显示文件夹，不解析符号链接
        );
    if(directory.isEmpty())
        return;
    QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();
    QSet<int> selectedRows;
    for (QTableWidgetItem *item : selectedItems) {
        selectedRows.insert(item->row());
    }
    for(int TemplateIndex:selectedRows)
        AnalysisJson::saveRuleTemplateToJson(m_Template[TemplateIndex],directory+"/"+m_Template[TemplateIndex].Name+".json");
}


void MainWindow::on_Import_triggered()
{
    QStringList file_name = QFileDialog::getOpenFileNames(this,"导入",".","*.json");
    if(file_name.isEmpty())
        return;
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


void MainWindow::on_Edit_triggered()
{
    // m_CreateRule->show();
    TemplateIndex=ui->tableWidget->currentRow();
    emit EditTemplate(m_Template[TemplateIndex]);
    m_CreateRule->show();
}


void MainWindow::on_Rename_triggered()
{
    m_ReName->show();
}

void MainWindow::ReNameComplete(QString Name, QString Des)
{
    TemplateIndex=ui->tableWidget->currentIndex().row();
    m_Template[TemplateIndex].Name=Name;
    m_Template[TemplateIndex].Description=Des;
    FlashTable();
}


void MainWindow::on_Copy_triggered()
{
    QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();

    // 使用QSet来避免重复的行索引
    QSet<int> selectedRows;
    RuleTemplate Temp;
    for (QTableWidgetItem *item : selectedItems) {
        selectedRows.insert(item->row());
    }
    for(int TemplateIndex:selectedRows)
    {
        Temp=m_Template[TemplateIndex];
        m_Template.append(Temp);
    }
    FlashTable();
}

