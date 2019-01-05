#include "chartviewer.h"
#include "ui_chartviewer.h"
#include<QResizeEvent>
ChartViewer::ChartViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChartViewer)
{
    ui->setupUi(this);
    viewer = new QChartView(ui->Display);
}
void ChartViewer::resizeEvent(QResizeEvent *event)
{
    ui->Display->setFixedSize(event->size().width(),event->size().height()-50);
    viewer->setFixedSize(ui->Display->width(),ui->Display->height()-40);
}

void ChartViewer::createChart(Chart *chart){
    viewer->setChart(chart);
}

ChartViewer::~ChartViewer()
{
    delete ui;
    delete viewer;
}

void ChartViewer::on_Themes_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        viewer->chart()->setTheme(QChart::ChartThemeLight);
        break;
    case 1:
        viewer->chart()->setTheme(QChart::ChartThemeBlueCerulean);
        break;
    case 2:
        viewer->chart()->setTheme(QChart::ChartThemeDark);
        break;
    case 3:
        viewer->chart()->setTheme(QChart::ChartThemeBrownSand);
        break;
    case 4:
        viewer->chart()->setTheme(QChart::ChartThemeBlueNcs);
    case 5:
        viewer->chart()->setTheme(QChart::ChartThemeHighContrast);
        break;
    case 6:
        viewer->chart()->setTheme(QChart::ChartThemeBlueIcy);
        break;
    case 7:
        viewer->chart()->setTheme(QChart::ChartThemeQt);
    default:
        break;
    }
}
