#ifndef COPYCELL_H
#define COPYCELL_H
#include <QModelIndex>
#include<QDebug>
class CopyCell{
private:
  int row,column;
  int count;
  QModelIndexList list;
public:
  CopyCell():row(0),column(0),count(0){}
  void setList(QModelIndexList li){
    list = li;
    count = list.count();
    setRowColumn();
   }
  QModelIndexList getList()const{return list;}
  int getRow()const{return row;}
  int getColumn()const{return column;}
  int getCount()const{return count;}
  void Disply(){
    qDebug()<<row<<":"<<column;
  }
private:
  void setRowColumn(){
    row =(1+list.at(count-1).row())-list.at(0).row();
    column =(1+list.at(count-1).column())-list.at(0).column();
  }
};
#endif // COPYCELL_H
