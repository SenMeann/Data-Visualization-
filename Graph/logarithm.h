#ifndef LOGARITHM_H
#define LOGARITHM_H
#include <QString>
#include <QVector>

struct XXYY{
    QVector<double>x;
    QVector<double>y;
};

class Logarithm
{
public:
    Logarithm();
    int getFirCoefficient(QString input);
    XXYY logPoly(QString input);
};

#endif // LOGARITHM_H
