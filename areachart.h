#ifndef AREACHART_H
#define AREACHART_H
#include<QtCharts/QAreaSeries>
#include<QtCharts/QBarCategoryAxis>
#include"chart.h"
class AreaChart:public Chart
{
public:
    AreaChart();
    void setBackground(int index);
    void creatChart(QModelIndexList list);
    void areaChart();
private:
    QModelIndexList List;
    int countColumn();
};

#endif // AREACHART_H
