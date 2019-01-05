#include "barchart.h"
#include<QVariant>
BarChart::BarChart(){
}
void BarChart::setBackground(int index){
    Q_UNUSED(index);
}
void BarChart::creatChart(QModelIndexList List){
    this->List = List;
}

void BarChart::columnBarChart(){
    int count = List.count();
    int column = countColumn();
    int row  = count/column;
    QBarSeries*series = new QBarSeries;
    QStringList list;
    QVariant v(List.at(1).data());
    if(v.convert(v.Double)){
        for(int i = 0 ; i< row ; i++){
             QBarSet*set = new QBarSet(List.at(i*column).data().toString());
             int n = (i*column)+1;
             for(int j = 0 ;j<column-1; j++){
                 double data  = List.at(n+j).data().toDouble();
                 set->append(data);
             }
        series->append(set);
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(QString::number(i));
        }
    }
    else {
        for(int i = 1 ; i< row ; i++){
             QBarSet*set = new QBarSet(List.at(i*column).data().toString());
             int n = (i*column)+1;
             for(int j = 0 ;j<column-1; j++){
                 double data  = List.at(n+j).data().toDouble();
                 set->append(data);
             }
        series->append(set);
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(List.at(i).data().toStringList());
        }
    }
   addSeries(series);
    QBarCategoryAxis*axis = new  QBarCategoryAxis;
    axis->append(list);
    createDefaultAxes();
    setAxisX(axis,series);
    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}
#include<QDebug>
void BarChart::rowBarChart(){
    int count = List.count();
    int column = countColumn();
    int row  = count/column;
    QHorizontalBarSeries*series = new QHorizontalBarSeries;
    QStringList list;
    QVariant v(List.at(1).data());
    if(v.convert(v.Double)){
        for(int i = 0 ; i< row ; i++){
             QBarSet*set = new QBarSet(List.at(i*column).data().toString());
             int n = (i*column)+1;
             for(int j = 0 ;j<column-1; j++){
                 double data  = List.at(n+j).data().toDouble();
                 set->append(data);
             }
        series->append(set);
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(QString::number(i));
        }
    }
    else {
        for(int i = 1 ; i< row ; i++){
             QBarSet*set = new QBarSet(List.at(i*column).data().toString());
             int n = (i*column)+1;
             for(int j = 0 ;j<column-1; j++){
                 double data  = List.at(n+j).data().toDouble();
                 set->append(data);
             }
        series->append(set);
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(List.at(i).data().toStringList());
        }
    }
   addSeries(series);
   QBarCategoryAxis*axisY = new  QBarCategoryAxis;
   axisY->append(list);
   createDefaultAxes();
   setAxisY(axisY,series);
   QValueAxis *axisX = new QValueAxis();
   setAxisX(axisX,series);
   axisX->applyNiceNumbers();
   legend()->setVisible(true);
   legend()->setAlignment(Qt::AlignBottom);
}
void BarChart::setCatories(){
}
int BarChart::countColumn()
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

int BarChart::counttRow()
{
    return (List.count()/countColumn());
}

