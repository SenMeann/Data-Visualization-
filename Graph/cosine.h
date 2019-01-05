#ifndef COSINE_H
#define COSINE_H
#include <QString>
#include <QVector>

struct XX{
    QVector <double> x;
    QVector <double> y;
};

class Cosine
{
public:
    Cosine();
    int getFirstCoefficient(QString input);
    XX cosPoly(QString input);
};

#endif // COSINE_H
