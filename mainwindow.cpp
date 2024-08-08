#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createrule.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_CreateRule=new CreateRule(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Create_triggered()
{
    m_CreateRule->show();
}

