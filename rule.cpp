#include "rule.h"

Rule::Rule()
{

}

Rule::Rule(int ruletype, int condition, QString column, QString CompareData)
{
    RT=ruletype;
    this->condition=condition;
    this->column=column;
    this->CompareData=CompareData;
}

Rule::Rule(int ruletype, int condition, QString column)
{
    RT=ruletype;
    this->condition=condition;
    this->column=column;
}



// bool Rule::CheckRule(const QXlsx::Cell* cell)
// {
//     switch (RT) {
//     case ExistRule:
//         if (condition == 0) {
//             return true;
//         } else if (condition == 1) {
//             return false;
//         } else if (condition.find("存在") != std::string::npos) {
//             // 处理“存在BCDEF中的N个”
//             QStringList list = QString::fromStdString(condition).remove("存在").split("中的");
//             QString letters = list[0];
//             int N = list[1].toInt();
//             int count = 0;
//             for (auto ch : letters) {
//                 if (ch == cell->value().toString()) {
//                     count++;
//                 }
//             }
//             return count >= N;
//         } else if (condition.find("不存在") != std::string::npos) {
//             // 处理“不存在BCDEF中的N个”
//             QStringList list = QString::fromStdString(condition).remove("不存在").split("中的");
//             QString letters = list[0];
//             int N = list[1].toInt();
//             int count = 0;
//             for (auto ch : letters) {
//                 if (ch == cell->value().toString()) {
//                     count++;
//                 }
//             }
//             return count == 0;
//         }
//         break;

//     case StringRule:
//     {
//         QString cellValue = cell->value().toString();
//         QString compareValue = QString::fromStdString(compareValue);
//         if (condition == "等于") {
//             return cellValue == compareValue;
//         } else if (condition == "不等于") {
//             return cellValue != compareValue;
//         } else if (condition == "包含") {
//             return cellValue.contains(compareValue);
//         } else if (condition == "不包含") {
//             return !cellValue.contains(compareValue);
//         } else if (condition.find("存在") != std::string::npos) {
//             QStringList list = QString::fromStdString(condition).remove("存在").split("中的");
//             QString letters = list[0];
//             int N = list[1].toInt();
//             int count = 0;
//             for (auto ch : letters) {
//                 if (cellValue.contains(ch)) {
//                     count++;
//                 }
//             }
//             return count >= N;
//         } else if (condition.find("不存在") != std::string::npos) {
//             QStringList list = QString::fromStdString(condition).remove("不存在").split("中的");
//             QString letters = list[0];
//             int N = list[1].toInt();
//             int count = 0;
//             for (auto ch : letters) {
//                 if (cellValue.contains(ch)) {
//                     count++;
//                 }
//             }
//             return count == 0;
//         }
//     }
//     break;

//     case NumberRule:
//     {
//         double cellValue = cell->value().toDouble();
//         double compareValue = std::stod(compareValue);

//         if (condition == "大于") {
//             return cellValue > compareValue;
//         } else if (condition == "小于") {
//             return cellValue < compareValue;
//         } else if (condition == "等于") {
//             return cellValue == compareValue;
//         } else if (condition == "不等于") {
//             return cellValue != compareValue;
//         }
//     }
//     break;

//     case TimeRule:
//     {
//         QDateTime cellValue = cell->value().toDateTime();
//         QDateTime compareValue = QDateTime::fromString(QString::fromStdString(compareValue), Qt::ISODate);

//         if (condition == "早于") {
//             return cellValue < compareValue;
//         } else if (condition == "晚于") {
//             return cellValue > compareValue;
//         } else if (condition == "等于") {
//             return cellValue == compareValue;
//         } else if (condition == "不等于") {
//             return cellValue != compareValue;
//         }
//     }
//     break;
//     }
//     return false;
// }
