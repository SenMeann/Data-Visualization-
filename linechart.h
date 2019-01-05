#ifndef LINECHART_H
#define LINECHART_H
#include"chart.h"
#include<QtCharts/QLineSeries>
#include<QtCharts/QBarCategoryAxis>
class LineChart:public Chart
{
public:
    LineChart();
    void setBackground(int index);
    void creatChart(QModelIndexList list);
    void lineChart();
private:
    QModelIndexList List;
    int countColumn();
    double getMax();
    double getMin();
};

#endif // LINECHART_H
