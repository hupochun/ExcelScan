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
public slots:
    void AddRule(Rule temp);

private slots:
    void on_Create_triggered();

private:
    Ui::CreateRule *ui;
};

#endif // CREATERULE_H
