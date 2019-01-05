#include "maininterface.h"
#include "ui_maininterface.h"
#include<QResizeEvent>
#include<QDebug>
#include<QMenu>
#include<QMessageBox>
#include"barchart.h"
#include"chartviewer.h"
#include"chart.h"
#include"piechart.h"
#include"Graph/graphshow.h"
#include"scatterchart.h"
#include"splinechart.h"
#include"linechart.h"
#include<QVariant>
#include"areachart.h"
#include<QFileDialog>
#include<readfile.h>
MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface),paste(0){
    ui->setupUi(this);
    addTableItemWidget();
    ui->Table->item(0,0)->setSelected(1);
    QVariant v;
 }
MainInterface::~MainInterface(){
  delete ui;}
void MainInterface::resizeEvent(QResizeEvent *event){
  ui->menu->setFixedWidth(event->size().width());
  ui->Menu->setFixedWidth(event->size().width());
  ui->Table->setFixedSize(event->size().width()-20,event->size().height()-170);
}
void MainInterface::copy_data_cell(){
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  copyIndexLis.setList(indexes);
}
void MainInterface::addTableItemWidget(){
  for(int i =0 ;i<99;i++)
    for(int j = 0 ;j<26;j++){
        QTableWidgetItem * pCell = new QTableWidgetItem;
        ui->Table->setItem(i,j,pCell);
      }
}
void MainInterface::setFontSize(const int value){//set size to data size
  QFont font;
  font.setPointSize(value);
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  int size = indexes.count();
  for(int i = 0 ;i<size ; i++){
      QModelIndex index=indexes.at(i);
      ui->Table->item(index.row(),index.column())->setFont(font);
    }
}
void MainInterface::setFont(const QString &font){//setfont
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  int size = indexes.count();
  for(int i = 0 ;i<size ; i++){
      QModelIndex index=indexes.at(i);
      QFont newFont = ui->Table->item(index.row(),index.column())->font();
      newFont.setFamily(font);
      ui->Table->item(index.row(),index.column())->setFont(QFont(newFont));
    }
}
void MainInterface::setTextColor(QColor &color){
   QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
   int size =indexes.count();
   for(int i = 0;i < size ;i++){
       QModelIndex index = indexes.at(i);
       ui->Table->item(index.row(),index.column())->setTextColor(color);
     }
}

void MainInterface::setAlignment(const int align){
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  int size =indexes.count();
  for(int i = 0;i < size ;i++){
      QModelIndex index = indexes.at(i);
      ui->Table->item(index.row(),index.column())->setTextAlignment(align);
    }
}
void MainInterface::setBackgorundCell(QColor& color){
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  int size =indexes.count();
  for(int i =0 ;i<size;i++){
      QModelIndex index= indexes.at(i);
      ui->Table->item(index.row(),index.column())->setBackground(QBrush(color));
    }
}

void MainInterface::display()
{
  ui->Table->item(2,2)->setText(ui->Table->item(0,0)->text());
  ui->Table->item(2,2)->setFont(ui->Table->item(0,0)->font());


}

bool MainInterface::isPaseted()const{
  return paste;
}

void MainInterface::setTextStyle(int index,bool TorF){
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  int size = indexes.count();
  if(index==1){
      for(int i = 0;i <size ; i++){
          QModelIndex list = indexes.at(i);
          QFont font =ui->Table->item(list.row(),list.column())->font();
          font.setBold(TorF);
          ui->Table->item(list.row(),list.column())->setFont(font);
        }
    }
  if(index==2){
      for(int i = 0;i <size ; i++){
          QModelIndex list = indexes.at(i);
          QFont font =ui->Table->item(list.row(),list.column())->font();
          font.setItalic(TorF);
          ui->Table->item(list.row(),list.column())->setFont(font);
        }
    }
  if(index==3){
      for(int i = 0;i <size ; i++){
          QModelIndex list = indexes.at(i);
          QFont font =ui->Table->item(list.row(),list.column())->font();
          font.setUnderline(TorF);
          ui->Table->item(list.row(),list.column())->setFont(font);
        }
    }
}

void MainInterface::setSelectionOneCell(int row, int column){
  ui->Table->reset();
  ui->Table->item(row,column)->setSelected(1);
}

void MainInterface::setSelectionOneCell(int row1, int column1, int row2, int column2){
  ui->Table->reset();
  for(int i =row1 ;i<row2;i++){
      for(int j =column1;j<column2;j++){
          ui->Table->item(i,j)->setSelected(true);
        }
  }
}

bool MainInterface::isselected(){
    QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
    int n = indexes.count();
    if(n > 1){
        if(indexes.at(0).column()+1 ==indexes.at(1).column() )
            return true;
        else return false;
    }
    else return false;
}

void MainInterface::creatchart(int i){
    QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
    if(i==1){
    BarChart*Bar = new BarChart;
    Chart*chart = Bar;
    chart->creatChart(indexes);
    Bar->columnBarChart();
    ChartViewer * viewer = new ChartViewer;
    viewer->createChart(chart);
    viewer->show();
    }
    else if(i == 2){
        BarChart*Bar = new BarChart;
        Chart*chart = Bar;
        chart->creatChart(indexes);
        Bar->rowBarChart();
        ChartViewer * viewer = new ChartViewer;
        viewer->createChart(chart);
        viewer->show();
    }
    else if(i == 3){
        PieChart*piechart = new PieChart;
        Chart*chart = piechart;
        chart->creatChart(indexes);
        piechart->pieChart();
        ChartViewer * viewer = new ChartViewer;
        viewer->createChart(chart);
        viewer->show();
    }
    else if(i == 4){
        ScatterChart* scatter = new ScatterChart;
        Chart*chart =scatter;
        chart->creatChart(indexes);
        scatter->scatterChart();
        ChartViewer * viewer = new ChartViewer;
        viewer->createChart(chart);
        viewer->show();

    }
    else if(i == 5){
        SplineChart* spline = new SplineChart;
        Chart*chart =spline;
        chart->creatChart(indexes);
        spline->splineChart();
        ChartViewer * viewer = new ChartViewer;
        viewer->createChart(chart);
        viewer->show();
    }
    else if(i == 6){
        LineChart* line = new LineChart;
        Chart*chart = line;
        chart->creatChart(indexes);
        line->lineChart();
        ChartViewer * viewer = new ChartViewer;
        viewer->createChart(chart);
        viewer->show();
    }
    else if(i == 7){
        AreaChart *area = new AreaChart;
        Chart*chart = area;
        chart->creatChart(indexes);
        area->areaChart();
        ChartViewer * viewer = new ChartViewer;
        viewer->createChart(chart);
        viewer->show();
    }
}

void MainInterface::creatGraph(){
    QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
    if(indexes.count() == 1){
        GraphShow* graph = new GraphShow();
        graph->getEquation(indexes.at(0).data().toString());
        graph->show();
    }

}
void MainInterface::on_Table_clicked(const QModelIndex &index){
  if (index.isValid()){}
}
void MainInterface::on_Table_customContextMenuRequested(const QPoint &pos){//option on table's cell
    QMenu * menu = new QMenu(this);
    menu->addAction(ui->actionCut);
    menu->addAction(ui->actionCopy);
    menu->addAction(ui->actionPaste);
    menu->popup(ui->Table->viewport()->mapToGlobal(pos));
}
void MainInterface::on_actionPaste_triggered()
{
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  int row , column;
  row    = (1+indexes.at(indexes.count()-1).row())-indexes.at(0).row();
  column = (1+indexes.at(indexes.count()-1).column())-indexes.at(0).column();
  QModelIndexList oldList = copyIndexLis.getList();
  if(copyIndexLis.getRow()==row && copyIndexLis.getColumn()==column){
      for(int i = 0 ;i<copyIndexLis.getCount();i++){
          QModelIndex indexNew = indexes.at(i);
          QModelIndex oldIndext =oldList.at(i);
          delete ui->Table->item(indexNew.row(),indexNew.column());
          ui->Table->setItem(indexNew.row(),indexNew.column(),
                             ui->Table->item(oldIndext.row(),oldIndext.column())->clone());
    }
}
  else {
      QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Comfirmation",
        "The content of the clipboard is"
        " bigger than the range"
        " selected.Do you want to insert it anyway?",QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            int n =  0;
            QModelIndex indexNew = indexes.at(0);
            QModelIndex oldIndext =oldList.at(0);
            for(int i = 0 ;i<copyIndexLis.getRow();i++)
              {
                for(int j =0 ;j<copyIndexLis.getColumn();j++)
                  {
                    oldIndext =oldList.at(n++);
                    delete ui->Table->item(indexNew.row()+i,indexNew.column()+j);
                    ui->Table->setItem(indexNew.row()+i,indexNew.column()+j,
                                       ui->Table->item(oldIndext.row(),oldIndext.column())->clone());
                  }
              }
        }
    }
  if(isPaseted()){
      for(int i = 0;i<copyIndexLis.getCount();i++)
        {
          QModelIndex oldIndext =oldList.at(i);
          ui->Table->item(oldIndext.row(),oldIndext.column())->setText("");
        }
      paste =0;
    }
}
void MainInterface::on_actionCopy_triggered(){
  copy_data_cell();
}
void MainInterface::on_actionCut_triggered(){
    copy_data_cell();
    paste =1;
}
void MainInterface::on_Table_itemSelectionChanged()
{
    QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
    if(indexes.count()==1){
        QString text=ui->Table->horizontalHeaderItem(indexes.at(indexes.count()-1).column())->text();
        text+=ui->Table->verticalHeaderItem(indexes.at(indexes.count()-1).row())->text();
        ui->Menu->setTextSearch(text);
      }
    else if(indexes.count()>1){
        QString text=ui->Table->horizontalHeaderItem(indexes.at(0).column())->text();
        text+=ui->Table->verticalHeaderItem(indexes.at(0).row())->text();
        text+=":";
        text+=ui->Table->horizontalHeaderItem(indexes.at(indexes.count()-1).column())->text();
        text+=ui->Table->verticalHeaderItem(indexes.at(indexes.count()-1).row())->text();
        ui->Menu->setTextSearch(text);
      }
}


void MainInterface::on_BFile_clicked()
{
    const QString fileName = QFileDialog::getOpenFileName(this,
      "Open file",QDir::rootPath(), "excel Files (*.xml)");
      if (!fileName.isEmpty())
      {
          ReadFile Read;
          Read.setFileName(fileName);
      }
}
QTableWidget *MainInterface::table()
{
    QTableWidget*mytable=ui->Table;
    return mytable;
}


