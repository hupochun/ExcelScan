#ifndef RULE_H
#define RULE_H

#include <QObject>
#include <QVector>
#include "xlsxdocument.h"


class Rule
{
public:
    Rule();
    Rule(int ruletype,int condition,QString column,QString CompareData);
    Rule(int ruletype,int condition,QString column);
    int RT;
    int condition;
    QString column;
    bool CheckRule();
    QString CompareData;
    QString Description;
    QString Name;


    bool CheckRule(const QXlsx::Cell *cell);
};

#endif // RULE_H
