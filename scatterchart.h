#ifndef SCATTERCHART_H
#define SCATTERCHART_H
#include"chart.h"
#include<QtCharts/QScatterSeries>
#include<QtCharts/QBarCategoryAxis>
class ScatterChart:public Chart
{
public:
    ScatterChart();
    void setBackground(int index);
    void creatChart(QModelIndexList list);
    void scatterChart();

private:
    QModelIndexList List;
    double getMax();
    double getMin();
    int countColumn();
};

#endif // SCATTERCHART_H
