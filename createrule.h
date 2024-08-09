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
    ~CreateRule();
signals:
    void AddRuleComplete(RuleTemplate temp);
public slots:
    void AddRule(Rule temp);
    void SolveDes(QString name,QString des);


private slots:
    void on_Create_triggered();

    void on_pushButton_released();



private:
    Ui::CreateRule *ui;
};

#endif // CREATERULE_H
