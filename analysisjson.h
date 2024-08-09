#ifndef ANALYSISJSON_H
#define ANALYSISJSON_H
#include "ruletemplate.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
class AnalysisJson
{
public:
    AnalysisJson();
    static QJsonObject errToJson(const Err& err);
    static QJsonObject ruleToJson(const Rule& rule);
    static QJsonObject ruleTemplateToJson(const RuleTemplate& ruleTemplate);
    static void saveRuleTemplateToJson(const RuleTemplate& ruleTemplate, const QString& filePath);
    static Err jsonToErr(const QJsonObject& jsonObj);
    static Rule jsonToRule(const QJsonObject& jsonObj);
    static RuleTemplate jsonToRuleTemplate(const QJsonObject& jsonObj);
    static RuleTemplate loadRuleTemplateFromJson(const QString& filePath);
};

#endif // ANALYSISJSON_H
