#ifndef RULE_H
#define RULE_H

#include <QObject>
#include <QVector>
#include "xlsxdocument.h"

struct Err
{
    int ErrRow;
    QChar ErrCol;
};

class Rule
{
public:
    Rule();
    Rule(int ruletype,int ruletype1,QString column,QString CompareData);
    Rule(int ruletype,int ruletype1,QString column);
    int RT;
    int RT1;
    int condition;
    QString column;
    void CheckRule(QXlsx::Document& xlsx);
    QString CompareData;
    QString Description;
    QString Name;
    QVector<Err> ErrMsg;
};

#endif // RULE_H
