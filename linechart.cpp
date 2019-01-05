#include "linechart.h"

LineChart::LineChart()
{

}

void LineChart::setBackground(int index)
{
    Q_UNUSED(index);
}

void LineChart::creatChart(QModelIndexList list)
{
    this->List = list;
}

void LineChart::lineChart()
{
    int count = List.count();
    int column = countColumn();
    int row  = count/column;
    QStringList list;
    QVariant v(List.at(1).data());
    if(v.convert(v.Double)){
        for(int i = 0 ; i<row ; i++){
            int n = (i*column)+1;
            int num =0 ;
            QLineSeries* line = new QLineSeries();
            line->setName(List.at(i*column).data().toString());
            for(int j = 0;j <column-1;j++){
                line->append(num,List.at(n+j).data().toDouble());
                num++;
            }
            addSeries(line);
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
            QLineSeries* line = new QLineSeries();
            line->setName(List.at(i*column).data().toString());
            for(int j = 0;j <column-1;j++){
                line->append(num,List.at(n+j).data().toDouble());
                num++;
            }
            addSeries(line);
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
        createDefaultAxes();
        setAxisX(axis,this->series().at(0));
    }
    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}

int LineChart::countColumn()
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

double LineChart::getMax()
{
    double max = List.at(1).data().toDouble();
    int count = List.count();
    for(int i = 3 ;i<count;i+=2){
        if(max < List.at(i).data().toDouble())
            max = List.at(i).data().toDouble();
    }
    return max;
}

double LineChart::getMin()
{
    double min = List.at(1).data().toDouble();
    int count = List.count();
    for(int i = 3 ;i<count;i+=2){
        if(min > List.at(i).data().toDouble())
            min = List.at(i).data().toDouble();
    }
    return min;
}
