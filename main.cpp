#include "maininterface.h"
#include <QApplication>
 MainInterface *w;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w =new MainInterface;
    w->show();
    return a.exec();
}
