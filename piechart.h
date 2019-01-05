#ifndef PIECHART_H
#define PIECHART_H
#include"chart.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

class PieChart:public Chart
{
public:
    PieChart();
    void setBackground(int index);
    void creatChart(QModelIndexList list);
    void pieChart();
private:
    QModelIndexList List;
    int countColumn();
};

#endif // PIECHART_H
