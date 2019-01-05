#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include<QCloseEvent>
#include"copycell.h"
#include<QTableWidgetItem>
namespace Ui{class MainInterface;}
class MainInterface : public QMainWindow,QCloseEvent{
    Q_OBJECT
public:
    explicit MainInterface(QWidget *parent = nullptr);
    ~MainInterface();
public:
  void resizeEvent(QResizeEvent *event);//event for get widht and height window
  void copy_data_cell();
  void addTableItemWidget();
  void setFontSize(const int value);
  void setFont(const QString&font);
  void setTextColor(QColor&color);
  void setAlignment(const int align);
  void setBackgorundCell(QColor& color);
  void display();
  bool isPaseted()const;
  void setTextStyle(int index,bool TorF);
  void setSelectionOneCell(int row,int column);
  void setSelectionOneCell(int row1,int column1,int row2,int column2);
  bool isselected();
  void creatchart(int i);
  void creatGraph();
  QTableWidget*table();
private slots:
  void on_Table_customContextMenuRequested(const QPoint &pos);
  void on_Table_clicked(const QModelIndex &index);
  void on_actionCut_triggered();
  void on_actionCopy_triggered();
  void on_actionPaste_triggered();
  void on_Table_itemSelectionChanged();
  void on_BFile_clicked();

private:
    Ui::MainInterface *ui;
    CopyCell copyIndexLis;
    bool paste;
};
#endif // MAININTERFACE_H
