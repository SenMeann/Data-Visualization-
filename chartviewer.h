#ifndef CHARTVIEWER_H
#define CHARTVIEWER_H
#include <QtCharts/QChartView>
#include<QCloseEvent>
QT_CHARTS_USE_NAMESPACE
#include <QWidget>
#include"chart.h"

namespace Ui {
class ChartViewer;
}

class ChartViewer : public QWidget,QCloseEvent
{
    Q_OBJECT
public:
    void resizeEvent(QResizeEvent *event);
    void setThemes();
    void createChart(Chart*chart);
public:
    explicit ChartViewer(QWidget *parent = nullptr);
    ~ChartViewer();

private slots:
    void on_Themes_currentIndexChanged(int index);

private:
    Ui::ChartViewer *ui;
    QChartView*viewer;
};

#endif // CHARTVIEWER_H
