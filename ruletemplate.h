#ifndef RULETEMPLATE_H
#define RULETEMPLATE_H

#include <QObject>
#include <QVector>
#include "rule.h"


class RuleTemplate
{
public:
    RuleTemplate();
    QVector<Rule> m_Rule;
    int RuleNum;


};

#endif // RULETEMPLATE_H
