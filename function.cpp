#include "function.h"
#include "ui_function.h"
Function::Function(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Function),completer(nullptr)
{
    ui->setupUi(this);
    ui->functions->setFocus();
    const QIcon funciontIcon(":/Icon/function.png");
    ui->functions->setClearButtonEnabled(true);
    ui->functions->addAction(funciontIcon, QLineEdit::LeadingPosition);
//    QString str1 = QString(QChar(0x221));
//    ui->functions->setText(str1);
    setCompleter();
}
QAbstractItemModel *Function::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << line.trimmed();
    }

#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    QStandardItemModel *m = new QStandardItemModel(words.count(), 2, completer);
    for (int i = 0; i < words.count(); ++i) {
        QModelIndex countryIdx = m->index(i, 0);
        QModelIndex symbolIdx = m->index(i, 1);
        QString country = words[i].mid(0, words[i].length() - 2).trimmed();
        QString symbol =QString::fromWCharArray(L"\u2A0D(x)");
        m->setData(symbolIdx, symbol);
        m->setData(countryIdx, country);
    }

    return m;
}

void Function::setCompleter(){
  completer = new QCompleter(this);
  QCompleter::CompletionMode mode;
  mode = QCompleter::PopupCompletion;
  completer->setCompletionMode(mode);
  completer->setCaseSensitivity(Qt::CaseInsensitive);
  completer->setModel(modelFromFile(":/resources/countries.txt"));
  QTreeView *treeView = new QTreeView;
  treeView->setFont(QFont("Times", 12));
  completer->setPopup(treeView);
  treeView->setRootIsDecorated(false);
  completer->setMaxVisibleItems(0);
  ui->functions->setCompleter(completer);
}

Function::~Function()
{
    delete ui;
}
#include<QDebug>


void Function::on_functions_textChanged(const QString &functions){
  std::string text=functions.toStdString();
  if(text[0]=='='){
      if(functions.size()>1){
          ui->functions->setText(functions.at(1));
          completer->setMaxVisibleItems(10);
        }
    }
  if(functions.size()==0){
      completer->setMaxVisibleItems(0);
    }
}
