#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <QString>
#include <regex>
#include <string>
#include<QVector>
struct XY{
    QVector<double>x;
    QVector<double>y;
};

class Polynomial
{
public:
    Polynomial();
    double *getCoeffecient(QString input);
    int firstCoeffcient(QString input);
    int countX(QString input);
    double getConstant(QString input);
    double *getPower(QString input);

   XY polyFunction(QString input);

private:

};

#endif // POLYNOMIAL_H
