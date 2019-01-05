#include "cosine.h"
#include "polynomial.h"
#include "sine.h"
Cosine::Cosine()
{

}

int Cosine::getFirstCoefficient(QString input)
{
    std::string FirCoeff = input.toStdString();
    if(FirCoeff[0] == '-' && FirCoeff[1] == 'c')
        FirCoeff = "-1";
    else if(FirCoeff[0] == 'c')
        FirCoeff = "1";
    int FirCo = atoi(FirCoeff.c_str());
    return FirCo;
}

XX Cosine::cosPoly(QString input)
{
    Polynomial poly;
    Sine sin;
    double y = 0;
    double x = 0;
    XX xy;
    xy.x.resize(201);
    xy.y.resize(201);
    while(x<=200){
        xy.x[static_cast<int>(x)] = x/4 - 25;
        for(int i=0; i<poly.countX(input); i++){
            y += static_cast<double>(poly.getCoeffecient(sin.getPoly(input))[i]) * pow(xy.x[static_cast<int>(x)], static_cast<double>(poly.getPower(sin.getPoly(input))[i]));
        }
        y += poly.getConstant(sin.getPoly(input));
        xy.y[static_cast<int>(x)] = this->getFirstCoefficient(input) * cos(y);
        y = 0;
        x++;
    }

    return xy;
}

