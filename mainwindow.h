#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createrule.h"
#include "templatedescription.h"
#include "xlsxdocument.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void FlashTable();

private slots:

    void on_Create_triggered();
    void AddTemplateFinished(RuleTemplate temp);

    void on_action_triggered();

    void on_action_Excel_triggered();
    void ShowErro();

    void on_Export_triggered();

    void on_Import_triggered();

    void on_Delete_triggered();

private:
    Ui::MainWindow *ui;
    CreateRule* m_CreateRule;
    QVector<RuleTemplate> m_Template;
    TemplateDescription* m_TemplateDescription;
    QString FileDir;
    int TemplateIndex;
};
#endif // MAINWINDOW_H
