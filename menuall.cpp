#include "menuall.h"
#include "ui_menuall.h"
#include "maininterface.h"
#include<QColorDialog>
#include<QMenu>
#include<regex>
#include<QtWidgets>
extern MainInterface*w;
MenuALL::MenuALL(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MenuALL),bold(0),italic(0),underline(0)
{
  ui->setupUi(this);
  setIcon();
  creatMenu();
  setSytesheet();
}
MenuALL::~MenuALL(){
  delete ui;
}
void MenuALL::Pattern1(std::string &str){
      mycell.column1 = int(str[0])-65;
      std::string row="";
      for(unsigned i = 1; i<str.length();i++)
        row+=str[i];
      mycell.row1 = std::stoi(row)-1;
}
void MenuALL::Pattern2(std::string &str){
  mycell.column1 = int(str[0])-65;
  std::string row1;
  unsigned i;
  char Break=':';
  for(i = 1 ;str[i]!=Break;i++){
      row1+=str[i];
    }
  mycell.row1 = std::stoi(row1)-1;
  mycell.column2 = int(str[++i])-65;
  i++;
  std::string row2="";
  for(;i<str.length();i++){
      row2+=str[i];
    }
  mycell.row2 = std::stoi(row2)-1;
  if(mycell.column1>mycell.column2){
      int temp1 = mycell.column2;
      mycell.column2=mycell.column1;
      mycell.column1 = temp1;
      int temp2   = mycell.row2;
      mycell.row2 = mycell.row1;
      mycell.row1 = temp2;

    }
}
void MenuALL::setTextSearch(QString &text){
  ui->Search->lineEdit()->setText(text);
}

void MenuALL::on_Font_currentTextChanged(const QString &font){
    if(!font.isEmpty())
      w->setFont(font);
}
void MenuALL::on_TextSize_currentTextChanged(const QString &size){
    if(!size.isEmpty())
      w->setFontSize(size.toInt());
}
void MenuALL::on_Background_clicked(){
 QColor color = QColorDialog::getColor();
 if(color.isValid())
   w->setBackgorundCell(color);
}
void MenuALL::on_TextColor_clicked(){
  QColor color = QColorDialog::getColor();
  if(color.isValid())
    w->setTextColor(color);
}

void MenuALL::on_Bold_clicked(){
  if(bold){bold = 0;w->setTextStyle(1,bold);}
  else {bold =1;w->setTextStyle(1,bold);}
}

void MenuALL::on_Italic_clicked(){
  if(italic){italic =0; w->setTextStyle(2,italic);}
  else{italic =1;w->setTextStyle(2,italic);}
}

void MenuALL::on_Underline_clicked(){
  if(underline){underline =0; w->setTextStyle(3,underline);}
  else{underline = 1;w->setTextStyle(3,underline);}
}

void MenuALL::on_AlignRight_clicked(){
  w->setAlignment(Qt::AlignRight);
}

void MenuALL::on_AlignCenter_clicked(){
    w->setAlignment(Qt::AlignCenter);
}

void MenuALL::on_AlignLeft_clicked(){
  w->setAlignment(Qt::AlignLeft);
}
void MenuALL::on_Search_currentIndexChanged(const QString &text)
{
  std::regex patter1(R"([[:upper:]]\d{1,2})");
  std::regex pattern2(R"([[:upper:]]\d{1,2}:[[:upper:]]\d{1,2})");
  std::string expresion = text.toStdString();
  if(std::regex_match(expresion,patter1)){
      Pattern1(expresion);
      w->setSelectionOneCell(mycell.row1,mycell.column1);
    }
  else
    if(std::regex_match(expresion,pattern2)){
        Pattern2(expresion);
        w->setSelectionOneCell(mycell.row1,mycell.column1,mycell.row2+1,mycell.column2+1);
    }
}

void MenuALL::creatBarChartColumn(){
    if(w->isselected()){
        w->creatchart(1);
    }
}

void MenuALL::createBarChartRow(){
    if(w->isselected()){
        w->creatchart(2);
    }
}

void MenuALL::creatPieChart()
{
    if(w->isselected()){
        w->creatchart(3);
    }
}

void MenuALL::creatScatterChart(){
if(w->isselected()){
    w->creatchart(4);
}
}

void MenuALL::creatSplineChart()
{
    if(w->isselected()){
        w->creatchart(5);
    }
}

void MenuALL::creatLineChart()
{
    if(w->isselected()){
        w->creatchart(6);
    }
}
void MenuALL::crateAreaChart()
{
    if(w->isselected()){
        w->creatchart(7);
    }
}
void MenuALL::creatMenuBarchar()
{
     QMenu * menu      = new QMenu;
     QWidget*widget    = new QWidget;
     QVBoxLayout*vbox  = new QVBoxLayout;
     QHBoxLayout*hbox1 = new QHBoxLayout;
     hbox1->setSpacing(12);
     //------------------------------------------------
     QLabel*labelCulumn= new QLabel("2-D Column");
     vbox->addWidget(labelCulumn);
     vbox->addItem(hbox1);
     QPushButton*clusterColumn = new QPushButton;
     clusterColumn->setFixedSize(50,50);
     clusterColumn->setIcon(QIcon(":/IconChart/clusetercolumn.png"));
     clusterColumn->setStyleSheet("border:none");
     clusterColumn->setIconSize(clusterColumn->size());
     QPushButton*stackedColumn=new QPushButton;
     stackedColumn->setFixedSize(50,50);
     stackedColumn->setIcon(QIcon(":/IconChart/stackedbarchart.png"));
     stackedColumn->setIconSize(stackedColumn->size());
     stackedColumn->setStyleSheet("border:none");
     hbox1->addWidget(clusterColumn);
     hbox1->addWidget(stackedColumn);
     //---------------------------------------------------
     QLabel*labelRow= new QLabel("2-D Row");
     vbox->addWidget(labelRow);
     QHBoxLayout*hbox2 = new QHBoxLayout;
     hbox2->setSpacing(12);
     vbox->addItem(hbox2);
     QPushButton*clusterRow = new QPushButton;
     clusterRow->setFixedSize(50,50);
     clusterRow->setIcon(QIcon(":/IconChart/cluseterrow.png"));
     clusterRow->setStyleSheet("border:none");
     clusterRow->setIconSize(clusterColumn->size());
     QPushButton*stackedRow=new QPushButton;
     stackedRow->setFixedSize(50,50);
     stackedRow->setIcon(QIcon(":/IconChart/stackedbarchartrow.png"));
     stackedRow->setIconSize(stackedColumn->size());
     stackedRow->setStyleSheet("border:none");
     hbox2->addWidget(clusterRow);
     hbox2->addWidget(stackedRow);
     //-----------------------------------------------------
     widget->setLayout(vbox);
     QWidgetAction *widAct = new QWidgetAction(this);
     widAct->setDefaultWidget(widget);
     menu->addAction(widAct);
     //signal
     connect(clusterColumn,SIGNAL(clicked()),this,SLOT(creatBarChartColumn()));
     connect(clusterRow,SIGNAL(clicked()),this,SLOT(createBarChartRow()));
     ui->Barchart->setMenu(menu);
}

void MenuALL::creatMenuPieChart(){
    QMenu*menu = new QMenu;
    QWidget*widget = new QWidget;
    QVBoxLayout*vbox = new QVBoxLayout;
    QHBoxLayout*hbox1 = new QHBoxLayout;
    hbox1->setSpacing(12);
    vbox->addWidget(new QLabel("2 D Pie"));
    QPushButton*pieButton = new QPushButton;
    pieButton->setFixedSize(50,50);
    pieButton->setIcon(QIcon(":/IconChart/piechart .png"));
    pieButton->setIconSize(pieButton->size());
    pieButton->setStyleSheet("border:none");
    QPushButton*pieOfpieButton = new QPushButton;
    pieOfpieButton->setFixedSize(pieButton->size());
    pieOfpieButton->setIcon(QIcon(":/IconChart/pie-chart.png"));
    pieOfpieButton->setIconSize(pieOfpieButton->size());
    pieOfpieButton->setStyleSheet("border:none");
    hbox1->addWidget(pieButton);
    hbox1->addWidget(pieOfpieButton);
    vbox->addItem(hbox1);
    vbox->addWidget(new QLabel("Doughnut"));
    QHBoxLayout*hbox2 = new QHBoxLayout;
    QPushButton*doughbut = new QPushButton;
    doughbut->setFixedSize(pieButton->size());
    doughbut->setIcon(QIcon(":/IconChart/Duonut.png"));
    doughbut->setIconSize(doughbut->size());
    doughbut->setStyleSheet("border:none");
    hbox2->addWidget(doughbut);
    vbox->addItem(hbox2);
    widget->setLayout(vbox);
    QWidgetAction*widAct = new QWidgetAction(this);
    widAct->setDefaultWidget(widget);
    menu->addAction(widAct);
    connect(pieButton,SIGNAL(clicked()),this,SLOT(creatPieChart()));
    ui->PieChart->setMenu(menu);
}
void MenuALL::creatMenuLine(){
    QMenu*menu = new QMenu;
    QWidget*widget = new QWidget;
    QVBoxLayout*vbox = new QVBoxLayout;
    vbox->addWidget(new QLabel("2 D line"));
    QHBoxLayout*hbox1 = new QHBoxLayout;
    hbox1->setSpacing(12);
    QPushButton*line = new QPushButton;
    line->setFixedSize(50,50);
    line->setIcon(QIcon(":/IconChart/lineChart.png"));
    line->setIconSize(line->size());
    QPushButton*LineMaker = new QPushButton;
    LineMaker->setFixedSize(line->size());
    LineMaker->setIcon(QIcon(":/IconChart/linescatter.png"));
    LineMaker->setIconSize(LineMaker->size());
    hbox1->addWidget(line);
    hbox1->addWidget(LineMaker);
    vbox->addItem(hbox1);
    vbox->addWidget(new QLabel("2 D Area"));
    QHBoxLayout*hbox2 = new QHBoxLayout;
    QPushButton*area = new QPushButton;
    area->setFixedSize(line->size());
    area->setIcon(QIcon(":/IconChart/area-chart.png"));
    area->setIconSize(area->size());
    hbox2->addWidget(area);
    vbox->addItem(hbox2);
    widget->setLayout(vbox);
    QWidgetAction*action = new  QWidgetAction(this);
    action->setDefaultWidget(widget);
    menu->addAction(action);
    connect(line,SIGNAL(clicked()),this,SLOT(creatLineChart()));
    connect(area,SIGNAL(clicked()),this,SLOT(crateAreaChart()));
    ui->LineChart->setMenu(menu);
}
void MenuALL::creatMenuScatterChart(){
    QMenu*menu = new QMenu;
    QWidget*widget = new QWidget;
    QVBoxLayout*vbox = new QVBoxLayout;
    vbox->addWidget(new QLabel("Scatter Chart"));
    QHBoxLayout*hbox1 = new QHBoxLayout;
    hbox1->setSpacing(12);
    QPushButton*buble = new QPushButton;
    buble->setFixedSize(50,50);
    buble->setIcon(QIcon(":/IconChart/scatter.png"));
    buble->setIconSize(buble->size());
    QPushButton*curveSmoot = new QPushButton;
    curveSmoot->setFixedSize(buble->size());
    curveSmoot->setIcon(QIcon(":/IconChart/scatterSmoth.png"));
    curveSmoot->setIconSize(curveSmoot->size());
    QPushButton*curve = new QPushButton;
    curve->setFixedSize(buble->size());
    curve->setIcon(QIcon(":/IconChart/curvechart.png"));
    curve->setIconSize(buble->size());
    hbox1->addWidget(buble);
    hbox1->addWidget(curveSmoot);
    hbox1->addWidget(curve);
    vbox->addItem(hbox1);
    widget->setLayout(vbox);
    QWidgetAction*action = new  QWidgetAction(this);
    action->setDefaultWidget(widget);
    menu->addAction(action);

    connect(buble,SIGNAL(clicked()),this,SLOT(creatScatterChart()));
    connect(curve,SIGNAL(clicked()),this,SLOT(creatSplineChart()));

    ui->ScatterChart->setMenu(menu);
}
void MenuALL::creatMenu(){
    creatMenuBarchar();
    creatMenuPieChart();
    creatMenuLine();
    creatMenuScatterChart();
}
void MenuALL::setSytesheet(){
}

void MenuALL::setIcon(){
    QLineEdit*line = new QLineEdit;
    ui->Search->setLineEdit(line);
    ui->Barchart->setIcon(QIcon(":/Icon/barchart.png"));
    ui->Background->setIcon(QIcon(":/Icon/fillcolor.png"));
    ui->PieChart->setIcon(QIcon(":/Icon/pie-chart.png"));
    ui->LineChart->setIcon(QIcon(":/Icon/line-chart.png"));
    ui->ScatterChart->setIcon(QIcon(":/Icon/scatter.png"));
    ui->graph->setIcon(QIcon(":/Icon/sine-wave-graphic.png"));
}

void MenuALL::on_graph_clicked(){
    w->creatGraph();
}
