#include "scatterchart.h"
ScatterChart::ScatterChart()
{

}
void ScatterChart::setBackground(int index){
Q_UNUSED(index);
}

void ScatterChart::creatChart(QModelIndexList list){
    this->List = list;
}
int ScatterChart::countColumn()
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

void ScatterChart::scatterChart(){
    int count = List.count();
    int column = countColumn();
    int row  = count/column;
    QStringList list;
    double max = List.at(1).data().toDouble();
    double min = max;
    QVariant v(List.at(1).data());
    if(v.convert(v.Double)){
        for(int i = 0 ; i<row ; i++){
            int n = (i*column)+1;
            int num =0 ;
            QScatterSeries* scatter = new QScatterSeries;
            scatter->setName(List.at(i*column).data().toString());
            for(int j = 0;j <column-1;j++){
                double data = List.at(n+j).data().toDouble();
                if(max <data){
                    max = data;
                }
                if(min>data)
                {
                    min = data;
                }
                scatter->append(num,data);
                num++;
            }
            addSeries(scatter);
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(QString::number(i));
        }
    }
    else{
        for(int i = 1 ; i<row ; i++){
            int n = (i*column)+1;
            int num =0 ;
            QScatterSeries* scatter = new QScatterSeries();
            scatter->setName(List.at(i*column).data().toString());
            for(int j = 0;j <column-1;j++){
                double data = List.at(n+j).data().toDouble();
                scatter->append(num,data);
                if(max <data){
                    max = data;
                }
                if(min>data)
                {
                    min = data;
                }
                num++;
            }
            addSeries(scatter);
        }
        for(int i = 1 ; i<column;i++)
        {
            list.append(List.at(i).data().toStringList());
        }
    }
    if(row>1){
        QBarCategoryAxis*axis = new  QBarCategoryAxis;
        axis->append(list);
        setAxisX(axis,this->series().at(0));
    }
    createDefaultAxes();
    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}

double ScatterChart::getMax()
{
    double max = List.at(1).data().toDouble();
    int count = List.count();
    for(int i = 3 ;i<count;i+=2){
        if(max < List.at(i).data().toDouble())
            max = List.at(i).data().toDouble();
    }
    return max;
}

double ScatterChart::getMin()
{
    double min = List.at(1).data().toDouble();
    int count = List.count();
    for(int i = 3 ;i<count;i+=2){
        if(min > List.at(i).data().toDouble())
            min = List.at(i).data().toDouble();
    }
    return min;
}
