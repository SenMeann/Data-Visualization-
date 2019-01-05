#include "maininterface.h"
#include "ui_maininterface.h"
#include<QResizeEvent>
#include<QDebug>
#include<QMenu>
#include<QMessageBox>
MainInterface::MainInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainInterface),paste(0){
    ui->setupUi(this);
    addTableItemWidget();
    const QIcon passwordIcon(":/Icon/function.png");
    ui->Function->setClearButtonEnabled(true);
    ui->Function->addAction(passwordIcon, QLineEdit::LeadingPosition);
 }
MainInterface::~MainInterface(){
  delete ui;}

void MainInterface::resizeEvent(QResizeEvent *event){
  ui->menu->setFixedWidth(event->size().width());
  ui->Table->setFixedSize(event->size().width()-20,event->size().height()-170);
}
void MainInterface::copy_data_cell(){
  QModelIndexList indexes = ui->Table->selectionModel()->selection().indexes();
  copyIndexLis.setList(indexes);
}
void MainInterface::addTableItemWidget(){
  for(int i =0 ;i<21;i++)
    for(int j = 0 ;j<17;j++){
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
  ui->Table->item(0,0)->setTextAlignment(align);
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
      for(int i = 0 ;i<copyIndexLis.getCount();i++)
        {
          QModelIndex indexNew = indexes.at(i);
          QModelIndex oldIndext =oldList.at(i);
          ui->Table->item(indexNew.row(),indexNew.column())
              ->setText(ui->Table->item(oldIndext.row(),oldIndext.column())->text());
          ui->Table->item(indexNew.row(),indexNew.column())
              ->setFont(ui->Table->item(oldIndext.row(),oldIndext.column())->font());
          ui->Table->item(indexNew.row(),indexNew.column())
              ->setBackground(ui->Table->item(oldIndext.row(),oldIndext.column())->background());
          ui->Table->item(indexNew.row(),indexNew.column())
              ->setTextColor(ui->Table->item(oldIndext.row(),oldIndext.column())->textColor());
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
                    ui->Table->item(indexNew.row()+i,indexNew.column()+j)
                        ->setText(ui->Table->item(oldIndext.row(),oldIndext.column())->text());
                    ui->Table->item(indexNew.row()+i,indexNew.column()+j)
                        ->setFont(ui->Table->item(oldIndext.row(),oldIndext.column())->font());
                    ui->Table->item(indexNew.row()+i,indexNew.column()+j)
                        ->setBackground(ui->Table->item(oldIndext.row(),oldIndext.column())->background());
                    ui->Table->item(indexNew.row()+i,indexNew.column()+j)
                        ->setTextColor(ui->Table->item(oldIndext.row(),oldIndext.column())->textColor());
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
