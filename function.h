#ifndef FUNCTION_H
#define FUNCTION_H
#include <QWidget>
#include <QCompleter>
#include<QTreeView>
#include<QFile>
#include<QStringList>
#include<QStringListModel>
#include<QStandardItemModel>
namespace Ui {
class Function;
}

class Function : public QWidget
{
    Q_OBJECT

public:
    explicit Function(QWidget *parent = nullptr);
    ~Function();

private slots:
  void on_functions_textChanged(const QString &functions);

private:
    Ui::Function *ui;
private:
    QAbstractItemModel *modelFromFile(const QString& fileName);
    QCompleter *completer;
    void setCompleter();
};

#endif // FUNCTION_H
