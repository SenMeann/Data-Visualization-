#ifndef MAININTERFACE_H
#define MAININTERFACE_H

#include <QMainWindow>
#include<QCloseEvent>
#include"copycell.h"
namespace Ui{class MainInterface;}
class MainInterface : public QMainWindow,QCloseEvent{
    Q_OBJECT
public:
    explicit MainInterface(QWidget *parent = 0);
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
private slots://slote for context menu table
  void on_Table_clicked(const QModelIndex &index);//click one cell
  void on_Table_customContextMenuRequested(const QPoint &pos);//select cell
  void on_actionPaste_triggered();
  void on_actionCopy_triggered();
  void on_actionCut_triggered();
private:
    Ui::MainInterface *ui;
    CopyCell copyIndexLis;
    bool paste;
};
#endif // MAININTERFACE_H
