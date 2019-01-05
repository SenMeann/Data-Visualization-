#ifndef SINE_H
#define SINE_H
#include <QString>
#include <QVector>
struct XYY{
    QVector<double>x;
    QVector<double>y;
};

class Sine
{
public:
    Sine();
    int getFirstCoefficient(QString input);
    QString getPoly(QString input);
    XYY sinePoly(QString input);
};

#endif // SINE_H
