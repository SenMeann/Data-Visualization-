#include "polynomial.h"
#include <QDebug>
Polynomial::Polynomial()
{

}

int Polynomial::firstCoeffcient(QString input){
    std::string FirCoeff = input.toStdString();
    if(FirCoeff[0] == '-' && FirCoeff[1] == 'x')
        FirCoeff = "-1";
    else if(FirCoeff[0] == 'x')
        FirCoeff = "1";
    int FirCo = atoi(FirCoeff.c_str());
    return FirCo;
}

int Polynomial::countX(QString input){
    int x = 0;
    for(int i=0; i<input.length(); i++){
        if(input[i] == 'x'){
            x++;
            continue;
        }
    }
    return x;
}

double Polynomial::getConstant(QString input){
    int i;
    QString constant = "";
    for(i=input.length(); i>0; i--){
        if(input[i] == '+' || input[i] == '-'){
            break;
        }
    }
    int j =0;
    for(j=0; j<input.length(); j++){
        if(input[j] == 'x'){
            constant = "0";
            return constant.toDouble();
        }
        else{
            constant+=input[j];
        }
    }
    return constant.toDouble();
}

double *Polynomial::getPower(QString input)
{
    QString A = "";
    double *p = new double[10];
    for (int u=0; u<10; u++){
        p[u] = 1;
    }
    int pos = this->countX(input);
    int i, j=0, k, l;
    for(k=0; k<pos; k++){

        for(i=j; i<input.length(); i++){
            if(input[i] == '^'){
                j = i+1;
                break;
            }
        }
        for(l=i; l<input.length(); l++){
            if(input[l] == '+' || input[l] == '-'){
                break;
            }
        }
        for(int f=i+1; f<l; f++){
            A = A + input[f];
        }
        p[k] = A.toDouble();
        if(p[k] == 0.0){
            p[k] = 1;
        }
        A = "";
    }
    return p;

}

double *Polynomial::getCoeffecient(QString input){
    QString A = "";
    double *p = new double[10];
    for (int u=0; u<10; u++){
        p[u] = 0;
    }
    p[0] = Polynomial::firstCoeffcient(input);
    int i, j=0, k, l;
    int pos = Polynomial::countX(input);
    for(k=1; k<=pos; k++){
        for(i=j; i<input.length(); i++){
            if(input[i] == '+' || input[i] == '-'){
                j = i+1;
                break;
            }
        }
        for(l=i; l<input.length(); l++){
            if(input[l] == 'x'){
                break;
            }
        }
        for(int f=i; f<l; f++){
            A = A + input[f];
        }
        p[k] = A.toDouble();
        if(p[k] == 0.0){
            p[k] = 1;
        }
        A = "";
    }
    return p;
}


XY Polynomial::polyFunction(QString input)
{
    int  x = 0;
    double y = 0;
    int i = 0;
    XY xy;
    xy.x.resize(201);
    xy.y.resize(201);
    while(x<=200){
        xy.x[x] = x/4 - 25;
        for (i=0; i<countX(input); i++){
            y = y + getCoeffecient(input)[i] * pow(xy.x[x], getPower(input)[i]);
        }
        xy.y[x] = y+getConstant(input);
        y = 0;
        i = 0;
        x++;
    }
    return xy;
}


