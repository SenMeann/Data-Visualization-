#ifndef SPLINECHART_H
#define SPLINECHART_H
#include"chart.h"
#include<QtCharts/QSplineSeries>
#include<QtCharts/QBarCategoryAxis>
class SplineChart:public Chart
{
public:
    SplineChart();
    void setBackground(int index);
    void creatChart(QModelIndexList list);
    void splineChart();
private:
    QModelIndexList List;
    double getMax();
    double getMin();
    int countColumn();
};

#endif // SPLINECHART_H
