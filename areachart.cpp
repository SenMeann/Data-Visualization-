#include "areachart.h"
#include<QtCharts/QLineSeries>
AreaChart::AreaChart()
{

}

void AreaChart::setBackground(int index)
{
    Q_UNUSED(index);

}

void AreaChart::creatChart(QModelIndexList list)
{
    this->List= list;
}

void AreaChart::areaChart()
{
    int count = List.count();
    int column = countColumn();
    int row  = count/column;
    QStringList list;
    QLineSeries *lowerSeries = nullptr;
    QVariant v(List.at(1).data());
    if(v.convert(v.Double)){
        for(int i = 0 ; i<row ; i++){
            int n = (i*column)+1;
            int num =0 ;
            QLineSeries*upperSeries = new QLineSeries(this);
            upperSeries->setName(List.at(i*column).data().toString());
            for(int j = 0;j <column-1;j++){
                upperSeries->append(num,List.at(n+j).data().toDouble());
                num++;
            }
            QAreaSeries *area = new QAreaSeries(upperSeries,lowerSeries);
            addSeries(area);
            createDefaultAxes();
            lowerSeries = upperSeries;
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(QString::number(i));
        }
    }
    else {
        for(int i = 1 ; i<row ; i++){
            int n = (i*column)+1;
            int num =0 ;
            QLineSeries*upperSeries = new QLineSeries(this);
            upperSeries->setName(List.at(i*column).data().toString());
            for(int j = 0;j <column-1;j++){
                upperSeries->append(num,List.at(n+j).data().toDouble());
                num++;
            }
            QAreaSeries *area = new QAreaSeries(upperSeries,lowerSeries);
            addSeries(area);
            createDefaultAxes();
            lowerSeries = upperSeries;
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(List.at(i).data().toStringList());
        }
    }
    createDefaultAxes();
    if(row>1){
        QBarCategoryAxis*axis = new  QBarCategoryAxis;
        axis->append(list);
        setAxisX(axis,this->series().at(0));
    }
    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}
int AreaChart::countColumn()
{
    int count = 1;
    int row = List.at(0).row();
    int i = 1;
    int nList = List.count();
    while (i < nList && row==List.at(i).row()) {
        count++;
        i++;
    }
    return count;
}
