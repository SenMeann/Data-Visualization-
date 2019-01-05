#include "logarithm.h"
#include "polynomial.h"
#include "sine.h"
Logarithm::Logarithm()
{

}

int Logarithm::getFirCoefficient(QString input)
{
    std::string FirCoeff = input.toStdString();
    if(FirCoeff[0] == '-' && FirCoeff[1] == 'l')
        FirCoeff = "-1";
    else if(FirCoeff[0] == 'l')
        FirCoeff = "1";
    int FirCo = atoi(FirCoeff.c_str());
    return FirCo;
}

XXYY Logarithm::logPoly(QString input)
{
    Polynomial poly;
    Sine sin;
    double y = 0;
    double x = 0;
    XXYY xy;
    xy.x.resize(201);
    xy.y.resize(201);
    while(x<=200){
        xy.x[static_cast<int>(x)] = x/4 - 25;
        for(int i=0; i<poly.countX(input); i++){
            y += static_cast<double>(poly.getCoeffecient(sin.getPoly(input))[i]) * pow(xy.x[static_cast<int>(x)],
                    static_cast<double>(poly.getPower(sin.getPoly(input))[i]));
        }
        y += poly.getConstant(sin.getPoly(input));
        xy.y[static_cast<int>(x)] = this->getFirCoefficient(input) * log10(y);
        y = 0;
        x++;
    }
    return xy;
}
