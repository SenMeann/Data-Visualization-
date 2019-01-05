#include "sine.h"
#include "polynomial.h"
Sine::Sine()
{

}

int Sine::getFirstCoefficient(QString input)
{
    std::string FirCoeff = input.toStdString();
    if(FirCoeff[0] == '-' && FirCoeff[1] == 's')
        FirCoeff = "-1";
    else if(FirCoeff[0] == 's')
        FirCoeff = "1";
    int FirCo = atoi(FirCoeff.c_str());
    return FirCo;
}

QString Sine::getPoly(QString input)
{
    QString Poly = "";
    int i, j;
    for(i=0; i<input.length(); i++){
        if(input[i] == '('){
            break;
        }
    }
    for(j=i; j<input.length(); j++){
        if(input[j] == ')')
            break;
    }

    for(int k=i+1; k<j; k++){
        Poly += input[k];
    }
    return Poly;
}

XYY Sine::sinePoly(QString input)
{
    Polynomial poly;
    double y = 0;
    double x = 0;
    XYY xy;
    xy.x.resize(201);
    xy.y.resize(201);
    while(x<=200){
        xy.x[static_cast<int>(x)] = x/4 - 25;
        for(int i=0; i<poly.countX(input); i++){
            y += static_cast<double>(poly.getCoeffecient(this->getPoly(input))[i]) * pow(xy.x[static_cast<int>(x)], static_cast<double>(poly.getPower(this->getPoly(input))[i]));
        }
        y += poly.getConstant(this->getPoly(input));
        xy.y[static_cast<int>(x)] = this->getFirstCoefficient(input) * sin(y);
        y = 0;
        x++;
    }
    return xy;
}
