#include "readfile.h"
#include <QtXml>
#include<QDebug>
#include<QFile>
#include<maininterface.h>
extern MainInterface *w;
ReadFile::ReadFile()
{

}
void ReadFile::setFileName(const QString &filename)
{
    QDomDocument document;
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"can't load file";
    }
    else {
        if(!document.setContent(&file)){
            qDebug()<<"can't load file";
        }
        else {
            QDomNodeList list=document.elementsByTagName("Row");
            int n=list.count();
            int row =list.at(0).toElement().attribute("ss:Index").toInt();
            setRow(list.at(0),row);
            for(int i=1;i<n;i++){
                int rowx = list.at(i).toElement().attribute("ss:Index").toInt();
                if(rowx==0){
                    rowx=row+1;
                    row =rowx;
                } else{
                   row = rowx;
                   rowx=rowx-1;
                }
                setRow(list.at(i),rowx);
            }
        }

    }
}

void ReadFile::setRow(QDomNode node,int row)
{  
   setCell(node.childNodes(),row);
}

void ReadFile::setCell(QDomNodeList list,int row)
{
    int n= list.count();
    int column = list.at(0).toElement().attribute("ss:Index").toInt();
    if(column!=0){
        column=column-1;
    }
    QString data =list.at(0).childNodes().at(0).childNodes().at(0).nodeValue();
    setDataToTable(row,column,data);
    for(int i =1;i<n;i++){
    QDomElement element = list.at(i).toElement();
    int columnx = element.attribute("ss:Index").toInt();
    QString datax=list.at(i).childNodes().at(0).childNodes().at(0).nodeValue();
    if(columnx==0){
     columnx=column+1;
     column =columnx;
    } else{
        column=columnx;
        columnx=columnx-1;
    }
    setDataToTable(row,columnx,datax);
    }
}

void ReadFile::setDataToTable(int row, int column, QString data)
{
    w->table()->item(row,column)->setText(data);
}
