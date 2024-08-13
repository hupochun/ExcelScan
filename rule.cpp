#include "rule.h"
#include <QTime>
Rule::Rule()
{
    condition=0;
}

Rule::Rule(int ruletype, int ruletype1, QString column, QString CompareData)
{
    RT=ruletype;
    this->RT1=ruletype1;
    this->column=column;
    this->CompareData=CompareData;
    condition=0;
}

Rule::Rule(int ruletype, int ruletype1, QString column)
{
    RT=ruletype;
    this->RT1=ruletype1;
    this->column=column;
    condition=0;
}

void Rule::CheckRule(QXlsx::Document& xlsx)
{
    if(xlsx.load())
    {
        if(RT1==0)//存在A
        {
            this->condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    if (cellValue.isEmpty()) {
                        ErrMsg.append({i,column[j]});
                        this->condition=0;
                    }
                }
            }
        }
        if(RT1==1)//不存在A
        {
            for(int j=0;j<column.length();j++)
            {
                this->condition=1;
                int col=column[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    if (!cellValue.isEmpty()) {
                        ErrMsg.append({i,column[j]});
                        this->condition=0;
                    }
                }
            }
        }
        if(RT1==2)//存在BCDEF中的N个
        {
            condition=0;
            int flag=0;
            int colnum=0;
            for(int j=0;j<column.length();j++)
            {
                flag=0;
                int col=column[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    if (cellValue.isEmpty()) {
                        ErrMsg.append({i,column[j]});
                    }
                    else
                    {
                        flag++;
                        if(flag==0)
                            colnum++;
                    }
                }
            }
            if(colnum>=CompareData.toInt())
                this->condition=1;
        }
        if(RT1==3)//不存在BCDEF中的N个
        {
            int flag=0;
            int colnum=0;
            for(int j=0;j<column.length();j++)
            {
                flag=0;
                int col=column[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    if (cellValue.isEmpty()) {
                        ErrMsg.append({i,column[j]});
                    }
                    else
                    {
                        flag++;
                        if(flag==0)
                            colnum++;
                    }
                }
            }
            if(colnum<=CompareData.toInt())
                this->condition=1;
        }
        if(RT1==4)//A等于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1!=cellValue) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==5)//A不等于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1==cellValue) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==6)//A内容为空
        {
            for(int j=0;j<column.length();j++)
            {
                this->condition=1;
                int col=column[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    if (!cellValue.isEmpty()) {
                        ErrMsg.append({i,column[j]});
                        this->condition=0;
                    }
                }
            }
        }
        if(RT1==7)//A内容不为空
        {
            for(int j=0;j<column.length();j++)
            {
                this->condition=1;
                int col=column[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    if (!cellValue.isEmpty()) {
                        ErrMsg.append({i,column[j]});
                        this->condition=0;
                    }
                }
            }
        }
        if(RT1==8)//A包含B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (!cellValue.contains(cellValue1)) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==9)//A不包含B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.contains(cellValue1)) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==10)//是BCDEF中的1个
        {
            int flag=0;
            for(int j=0;j<CompareData.length();j++)
            {
                flag=0;
                int col=column[0].toUpper().unicode()-'A'+1;
                int col1=CompareData[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1!=cellValue1) {
                        ErrMsg.append({i,column[j]});
                        flag++;
                    }
                }
                if(flag==0)
                {
                    condition=1;
                }
            }
        }
        if(RT1==11)//不是BCDEF中的1个
        {
            int flag=0;
            for(int j=0;j<CompareData.length();j++)
            {
                flag=0;
                int col=column[0].toUpper().unicode()-'A'+1;
                int col1=CompareData[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1==cellValue1) {
                        ErrMsg.append({i,column[j]});
                        flag++;
                    }
                }
                if(flag==0)
                {
                    condition=1;
                }
            }
        }
        if(RT1==12)//A小于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.toInt()>=cellValue1.toInt()) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==13)//A小于等于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.toInt()>cellValue1.toInt()) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==14)//A大于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.toInt()<=cellValue1.toInt()) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==15)//A大于等于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.toInt()<cellValue1.toInt()) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==16)//A等于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.toInt()!=cellValue1.toInt()) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==17)//A不等于B
        {
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue.toInt()==cellValue1.toInt()) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==18)//是BCDEF中的1个
        {
            int flag=0;
            for(int j=0;j<CompareData.length();j++)
            {
                flag=0;
                int col=column[0].toUpper().unicode()-'A'+1;
                int col1=CompareData[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1!=cellValue1) {
                        ErrMsg.append({i,column[j]});
                        flag++;
                    }
                }
                if(flag==0)
                {
                    condition=1;
                }
            }
        }
        if(RT1==19)//不是BCDEF中的1个
        {
            int flag=0;
            for(int j=0;j<CompareData.length();j++)
            {
                flag=0;
                int col=column[0].toUpper().unicode()-'A'+1;
                int col1=CompareData[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1==cellValue1) {
                        ErrMsg.append({i,column[j]});
                        flag++;
                    }
                }
                if(flag==0)
                {
                    condition=1;
                }
            }
        }
        if(RT1==20)//A早于B
        {
            QTime t1,t2;
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if(RT==2)
                    {
                        t1=QTime::fromString(cellValue,"hh::mm::ss");
                        t2=QTime::fromString(cellValue1,"hh::mm::ss");
                    }
                    if(RT==3)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd");
                    }
                    if(RT==4)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd hh:mm:ss");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd hh:mm:ss");
                    }
                    if (t1>=t2) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==21)//A早于等于B
        {
            QTime t1,t2;
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if(RT==2)
                    {
                        t1=QTime::fromString(cellValue,"hh::mm::ss");
                        t2=QTime::fromString(cellValue1,"hh::mm::ss");
                    }
                    if(RT==3)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd");
                    }
                    if(RT==4)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd hh:mm:ss");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd hh:mm:ss");
                    }
                    if (t1>t2) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==22)//A晚于B
        {
            QTime t1,t2;
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if(RT==2)
                    {
                        t1=QTime::fromString(cellValue,"hh::mm::ss");
                        t2=QTime::fromString(cellValue1,"hh::mm::ss");
                    }
                    if(RT==3)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd");
                    }
                    if(RT==4)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd hh:mm:ss");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd hh:mm:ss");
                    }
                    if (t1<=t2) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }
        }
        if(RT1==23)//A晚于等于B
        {
            QTime t1,t2;
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if(RT==2)
                    {
                        t1=QTime::fromString(cellValue,"hh::mm::ss");
                        t2=QTime::fromString(cellValue1,"hh::mm::ss");
                    }
                    if(RT==3)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd");
                    }
                    if(RT==4)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd hh:mm:ss");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd hh:mm:ss");
                    }
                    if (t1<t2) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }

        }
        if(RT1==24)//A和B时间相同
        {
            QTime t1,t2;
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if(RT==2)
                    {
                        t1=QTime::fromString(cellValue,"hh::mm::ss");
                        t2=QTime::fromString(cellValue1,"hh::mm::ss");
                    }
                    if(RT==3)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd");
                    }
                    if(RT==4)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd hh:mm:ss");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd hh:mm:ss");
                    }
                    if (t1!=t2) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }

        }
        if(RT1==26)//A在B和C时间范围内
        {
            QTime t1,t2,t3;
            condition=1;
            for(int j=0;j<column.length();j++)
            {
                int col=column[j].toUpper().unicode()-'A'+1;
                int col1=CompareData[0].toUpper().unicode()-'A'+1;
                int col2=CompareData[1].toUpper().unicode()-'A'+1;
                QStringList parts1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    QString cellValue2 = xlsx.cellAt(i,col2)?xlsx.cellAt(i,col2)->value().toString():"";
                    if(RT==2)
                    {
                        t1=QTime::fromString(cellValue,"hh::mm::ss");
                        t2=QTime::fromString(cellValue1,"hh::mm::ss");
                        t3=QTime::fromString(cellValue2,"hh::mm::ss");
                    }
                    if(RT==3)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd");
                        t3=QTime::fromString(cellValue2,"yyyy-MM-dd");
                    }
                    if(RT==4)
                    {
                        t1=QTime::fromString(cellValue,"yyyy-MM-dd hh:mm:ss");
                        t2=QTime::fromString(cellValue1,"yyyy-MM-dd hh:mm:ss");
                        t3=QTime::fromString(cellValue2,"yyyy-MM-dd hh:mm:ss");
                    }
                    if (t1<t2||t1>t3) {
                        ErrMsg.append({i,column[j]});
                        condition=0;
                    }
                }
            }

        }
        if(RT1==27)//是BCDEF中的1个
        {
            int flag=0;
            for(int j=0;j<CompareData.length();j++)
            {
                flag=0;
                int col=column[0].toUpper().unicode()-'A'+1;
                int col1=CompareData[j].toUpper().unicode()-'A'+1;
                for(int i=1;i<=xlsx.dimension().lastRow();i++)
                {
                    QString cellValue = xlsx.cellAt(i,col)?xlsx.cellAt(i,col)->value().toString():"";
                    QString cellValue1 = xlsx.cellAt(i,col1)?xlsx.cellAt(i,col1)->value().toString():"";
                    if (cellValue1!=cellValue1) {
                        ErrMsg.append({i,column[j]});
                        flag++;
                    }
                }
                if(flag==0)
                {
                    condition=1;
                }
            }
        }

    }
}

QString Rule::GetType()
{
    switch (this->RT) {
    case 0:
        return "字符串";
        break;
    case 1:
        return "是否";
    case 2:
        return "时分秒";
    case 3:
        return "年月日";
    case 4:
        return "年月日时分秒";
    case 5:
        return "数字";
    case 6:
        return "小数";
    case 7:
        return "百分比";

    default:
        break;
    }


}
