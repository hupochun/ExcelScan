#ifndef MAKERULE_H
#define MAKERULE_H

#include <QDialog>
#include "rule.h"
namespace Ui {
class MakeRule;
}

class MakeRule : public QDialog
{
    Q_OBJECT

public:
    explicit MakeRule(QWidget *parent = nullptr);

    ~MakeRule();

public slots:
    void ui_clear();
private slots:
    void on_pushButton_2_released();

    void on_pushButton_released();

    void on_comboBox_activated(int index);


signals:
    void CreateFinished(Rule rule);
private:
    Ui::MakeRule *ui;
    int index1;
    int index2;
};

#endif // MAKERULE_H
