#ifndef RENAME_H
#define RENAME_H

#include <QDialog>

namespace Ui {
class Rename;
}

class Rename : public QDialog
{
    Q_OBJECT

public:
    explicit Rename(QWidget *parent = nullptr);

    ~Rename();
signals:
    void RenameComplete(QString Name,QString Des);
private slots:
    void on_pushButton_released();

private:
    Ui::Rename *ui;
};

#endif // RENAME_H
