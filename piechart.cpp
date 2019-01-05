#include "piechart.h"
PieChart::PieChart()
{

}

void PieChart::setBackground(int index){
Q_UNUSED(index);
}
int PieChart::countColumn()
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
void PieChart::creatChart(QModelIndexList list){
    this->List = list;
}
void PieChart::pieChart(){

    QPieSeries*series = new QPieSeries;
    int count = List.count();
    if(count/countColumn()>1)
    for(int i = 0; i<count ;i=i+2){
        series->append(List.at(i).data().toString(),List.at(i+1).data().toDouble());
    }
    else {
        series->append(List.at(0).data().toString(),List.at(1).data().toDouble());
    }
    addSeries(series);
}
