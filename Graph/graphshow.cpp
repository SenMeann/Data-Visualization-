#include "graphshow.h"
#include "polynomial.h"
#include "sine.h"
#include "cosine.h"
#include "logarithm.h"
#include "ui_graphshow.h"
#include <QMessageBox>

GraphShow::GraphShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphShow)
{
    ui->setupUi(this);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->customPlot->xAxis->setRange(-25, 25);
    ui->customPlot->yAxis->setRange(-20, 20);
    ui->customPlot->axisRect()->setupFullAxesBox();
}

GraphShow::~GraphShow()
{
    delete ui;
}

void GraphShow::getEquation(QString equation)
{
    std::string input = equation.toStdString();
    std::regex polynomial("([-]|[+])?([0-9]?[0-9])?(x[^]?"
                          "[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?"
                          "([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])"
                          "?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?"
                          "[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?"
                          "([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])"
                          "?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?"
                          "([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9]"
                          ")?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?"
                          "([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)"
                          "?([-]|[+])?([0-9]?[0-9])?");
    std::regex sine("([-]|[+])?([0-9]?[0-9])?sin[(]([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?"
                    "([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?"
                    "([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?"
                    "([0-9]?[0-9])?([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?"
                    "([0-9]?[0-9])?[)]");
    std::regex cosine("([-]|[+])?([0-9]?[0-9])?cos[(]([-]|[+])?([0-9]?[0-9])?"
                      "(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?"
                      "[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?"
                      "([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?"
                      "([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?[)]");
    std::regex logarithm("([-]|[+])?([0-9]?[0-9])?log[(]([-]|[+])?([0-9]?[0-9])?"
                         "(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?([0-9]?"
                         "[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?([-]|[+])?"
                         "([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?"
                         "([-]|[+])?([0-9]?[0-9])?(x[^]?[0-9]?)?([-]|[+])?([0-9]?[0-9])?[)]");


    bool match_poly = regex_match(input, polynomial);
    bool match_sine = regex_match(input, sine);
    bool match_cosine = regex_match(input, cosine);
    bool match_logarithm = regex_match(input, logarithm);
    if(match_poly){
        Polynomial poly;
        poly.polyFunction(equation);
        ui->customPlot->addGraph();
        XY xy;
        xy = poly.polyFunction(equation);
        ui->customPlot->graph(0)->setPen(QPen(Qt::red,2));
        ui->customPlot->graph(0)->setData(xy.x, xy.y);
        ui->customPlot->replot();
    }
    else if(match_sine){
        Sine sine;
        sine.sinePoly(equation);
        ui->customPlot->addGraph();
        XYY xy;
        xy = sine.sinePoly(equation);
        ui->customPlot->graph(0)->setPen(QPen(Qt::red,2));
        ui->customPlot->graph(0)->setData(xy.x, xy.y);
        ui->customPlot->replot();
    }
    else if(match_cosine){
        Cosine cos;
        cos.cosPoly(equation);
        ui->customPlot->addGraph();
        XX xy;
        xy = cos.cosPoly(equation);
        ui->customPlot->graph(0)->setPen(QPen(Qt::red,2));
        ui->customPlot->graph(0)->setData(xy.x, xy.y);
        ui->customPlot->replot();
    }
    else if(match_logarithm){
        Logarithm log;
        log.logPoly(equation);
        ui->customPlot->addGraph();
        XXYY xy;
        xy = log.logPoly(equation);
        ui->customPlot->graph(0)->setPen(QPen(Qt::red,2));
        ui->customPlot->graph(0)->setData(xy.x, xy.y);
        ui->customPlot->replot();
    }

}


