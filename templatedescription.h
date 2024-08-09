#ifndef TEMPLATEDESCRIPTION_H
#define TEMPLATEDESCRIPTION_H

#include <QDialog>

namespace Ui {
class TemplateDescription;
}

class TemplateDescription : public QDialog
{
    Q_OBJECT

public:
    explicit TemplateDescription(QWidget *parent = nullptr);
    ~TemplateDescription();
signals:
    void TemplateDescriFinished(QString name,QString des);
private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::TemplateDescription *ui;
};

#endif // TEMPLATEDESCRIPTION_H
