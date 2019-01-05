#ifndef MENUALL_H
#define MENUALL_H
#include <QWidget>
struct Cell{
  int row1;
  int column1;
  int row2;
  int column2;
  Cell() {}
};
namespace Ui {
  class MenuALL;
}

class MenuALL : public QWidget{
  Q_OBJECT

public:
  explicit MenuALL(QWidget *parent = nullptr);
  ~MenuALL();
public:
    void setTextSearch(QString&text);
    void setSytesheet();
    void setIcon();
    void creatMenuBarchar();
    void creatMenuPieChart();
    void creatMenuLine();
    void creatMenuScatterChart();
    void creatMenu();
    enum chart{BarColum,Barrow};
private slots:
  void on_Font_currentTextChanged(const QString &font);
  void on_TextSize_currentTextChanged(const QString &size);
  void on_Background_clicked();
  void on_TextColor_clicked();
  void on_Bold_clicked();
  void on_Italic_clicked();
  void on_Underline_clicked();
  void on_AlignRight_clicked();
  void on_AlignCenter_clicked();
  void on_AlignLeft_clicked();
  void on_Search_currentIndexChanged(const QString &text);
  void creatBarChartColumn();
  void createBarChartRow();
  void creatPieChart();
  void creatScatterChart();
  void creatSplineChart();
  void creatLineChart();
  void crateAreaChart();
  void on_graph_clicked();

private:
  Ui::MenuALL *ui;
  bool bold;
  bool italic;
  bool underline;
  Cell mycell;
  void Pattern1(std::string &str);
  void Pattern2(std::string &str);
};

#endif // MENUALL_H
