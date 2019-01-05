#ifndef GRAPHSHOW_H
#define GRAPHSHOW_H

#include <QWidget>
#include <QString>
#include <string.h>
#include <regex>

namespace Ui {
class GraphShow;
}

class GraphShow : public QWidget
{
    Q_OBJECT

public:
    explicit GraphShow(QWidget *parent = nullptr);
    ~GraphShow();
    void getEquation(QString equation);

private:
    Ui::GraphShow *ui;
};

#endif // GRAPHSHOW_H
