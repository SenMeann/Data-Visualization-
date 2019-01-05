#ifndef BARCHART_H
#define BARCHART_H
#include"chart.h"
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarLegendMarker>
#include<QtCharts/QBarSet>
#include<QtCharts/QBarCategoryAxis>
#include<vector>
#include<QValueAxis>
#include<QHorizontalBarSeries>
class BarChart:public Chart
{
public:
    BarChart();
    void setBackground(int index);
    void creatChart(QModelIndexList List);
    void columnBarChart();
    void rowBarChart();
private:
    void setCatories();
    int countColumn();
    int counttRow();
    QModelIndexList List;
};

#endif // BARCHART_H
