#ifndef CHART_H
#define CHART_H
#include<QtCharts/QChart>
#include<QModelIndexList>
QT_CHARTS_USE_NAMESPACE
enum theme{

};

class Chart:public QChart
{
public:
    virtual void setBackground(int index)=0;
    virtual void creatChart(QModelIndexList list) = 0;
};

#endif // CHART_H

