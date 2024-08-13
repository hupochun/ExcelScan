#ifndef CREATERULE_H
#define CREATERULE_H

#include <QMainWindow>
#include "makerule.h"
#include "ruletemplate.h"
namespace Ui {
class CreateRule;
}

class CreateRule : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateRule(QWidget *parent = nullptr);
    MakeRule* m_MakeRule;
    RuleTemplate Template;
    void FlashTable();
    bool IsRevise;
    ~CreateRule();
signals:
    void AddRuleComplete(RuleTemplate temp,bool isRevise);
    void makerule_clear();
public slots:
    void AddRule(Rule temp);
    void SolveDes(QString name,QString des);
    void ReceiveTemplate(RuleTemplate Temp);



private slots:
    void on_Create_triggered();

    void on_pushButton_released();



    void on_Delete_triggered();

private:
    Ui::CreateRule *ui;
};

#endif // CREATERULE_H
