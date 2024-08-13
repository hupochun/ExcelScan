#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createrule.h"
#include "templatedescription.h"
#include "xlsxdocument.h"
#include "rename.h"
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
    QColor randomQtColor();
    void updateCellColor(QXlsx::Document &xlsx, const QString &cell, const QColor &color);

private slots:

    void on_Create_triggered();
    void AddTemplateFinished(RuleTemplate temp,bool isRevise);

    void on_action_triggered();

    void on_action_Excel_triggered();

    void on_Export_triggered();

    void on_Import_triggered();

    void on_Delete_triggered();

    void on_Edit_triggered();

    void on_Rename_triggered();

    void on_Copy_triggered();

signals:
    void EditTemplate(RuleTemplate Template);


public slots:
    void ReNameComplete(QString Name,QString Des);
private:
    Ui::MainWindow *ui;
    CreateRule* m_CreateRule;
    QVector<RuleTemplate> m_Template;
    TemplateDescription* m_TemplateDescription;
    QString FileDir;
    int TemplateIndex;
    Rename* m_ReName;

};
#endif // MAINWINDOW_H
