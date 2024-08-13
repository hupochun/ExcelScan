#include "analysisjson.h"

AnalysisJson::AnalysisJson() {}

// QJsonObject AnalysisJson::errToJson(const Err &err)
// {
//     QJsonObject jsonObj;
//     jsonObj["ErrRow"] = err.ErrRow;
//     jsonObj["ErrCol"] = QString(err.ErrCol);
//     return jsonObj;
// }

QJsonObject AnalysisJson::ruleToJson(const Rule &rule)
{
    QJsonObject jsonObj;
    jsonObj["RT"] = rule.RT;
    jsonObj["RT1"] = rule.RT1;
    jsonObj["condition"] = rule.condition;
    jsonObj["column"] = rule.column;
    jsonObj["CompareData"] = rule.CompareData;
    jsonObj["Description"] = rule.Description;
    jsonObj["Name"] = rule.Name;

    // QJsonArray errArray;
    // for (const Err& err : rule.ErrMsg) {
    //     errArray.append(errToJson(err));
    // }
    // jsonObj["ErrMsg"] = errArray;

    return jsonObj;
}

QJsonObject AnalysisJson::ruleTemplateToJson(const RuleTemplate &ruleTemplate)
{
    QJsonObject jsonObj;
    jsonObj["RuleNum"] = ruleTemplate.RuleNum;
    jsonObj["Name"] = ruleTemplate.Name;
    jsonObj["Description"] = ruleTemplate.Description;

    QJsonArray ruleArray;
    for (const Rule& rule : ruleTemplate.m_Rule) {
        ruleArray.append(ruleToJson(rule));
    }
    jsonObj["Rules"] = ruleArray;

    return jsonObj;
}

void AnalysisJson::saveRuleTemplateToJson(const RuleTemplate &ruleTemplate, const QString &filePath)
{
    QJsonObject jsonObj = ruleTemplateToJson(ruleTemplate);
    QJsonDocument jsonDoc(jsonObj);
    QByteArray jsonData = jsonDoc.toJson();

    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        stream << jsonData;
        file.close();
    } else {
        qWarning() << "Failed to open file for writing:" << filePath;
    }
}

// Err AnalysisJson::jsonToErr(const QJsonObject &jsonObj)
// {
//     Err err;
//     err.ErrRow = jsonObj["ErrRow"].toInt();
//     err.ErrCol = jsonObj["ErrCol"].toString().at(0).toLatin1();
//     return err;
// }

Rule AnalysisJson::jsonToRule(const QJsonObject &jsonObj)
{
    Rule rule;
    rule.RT = jsonObj["RT"].toInt();
    rule.RT1 = jsonObj["RT1"].toInt();
    rule.condition = jsonObj["condition"].toString().toInt();
    rule.column = jsonObj["column"].toString();
    rule.CompareData = jsonObj["CompareData"].toString();
    rule.Description = jsonObj["Description"].toString();
    rule.Name = jsonObj["Name"].toString();

    // QJsonArray errArray = jsonObj["ErrMsg"].toArray();
    // for (const QJsonValue& value : errArray) {
    //     rule.ErrMsg.append(jsonToErr(value.toObject()));
    // }

    return rule;
}

RuleTemplate AnalysisJson::jsonToRuleTemplate(const QJsonObject &jsonObj)
{
    RuleTemplate ruleTemplate;
    ruleTemplate.RuleNum = jsonObj["RuleNum"].toInt();
    ruleTemplate.Name = jsonObj["Name"].toString();
    ruleTemplate.Description = jsonObj["Description"].toString();

    QJsonArray ruleArray = jsonObj["Rules"].toArray();
    for (const QJsonValue& value : ruleArray) {
        ruleTemplate.m_Rule.append(jsonToRule(value.toObject()));
    }

    return ruleTemplate;
}

RuleTemplate AnalysisJson::loadRuleTemplateFromJson(const QString &filePath)
{
    QFile file(filePath);
    RuleTemplate ruleTemplate;

    if (file.open(QIODevice::ReadOnly| QIODevice::Text)) {

        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        QByteArray jsonData = stream.readAll().toUtf8();
        file.close();

        QJsonDocument jsonDoc(QJsonDocument::fromJson(jsonData));
        QJsonObject jsonObj = jsonDoc.object();
        ruleTemplate = jsonToRuleTemplate(jsonObj);
    } else {
        qWarning() << "Failed to open file for reading:" << filePath;
    }

    return ruleTemplate;
}
