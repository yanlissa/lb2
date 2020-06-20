#pragma once

#include <iostream>
#include <algorithm>
#include "Exception.h"

using namespace std;

class Vector
{
    double *dest;
    int n;
public:
    Vector(){
        dest=new double[0];
    }
    Vector(int n):n(n){
        dest=new double[n]{0};
    }
    Vector(int n,double *values):n(n){
        dest=new double[n];
        copy(values,values+n,dest);
    }
    virtual ~Vector(){
        delete[] dest;
    }

    Vector(const Vector &vector);

    double length();

    int getDimension()const;

    Vector&operator=(const Vector &vector);

    Vector operator+(const Vector &vector)const;

    Vector operator+();

    Vector operator-(const Vector &vector)const;

    Vector operator-();

    Vector& operator+=(const Vector &vector);

    Vector& operator-=(const Vector &vector);

    Vector operator*(double value)const;

    double operator*(const Vector &vector)const;

    friend Vector operator*(double value,const Vector &vector);

    friend ostream&operator<<(ostream &os,const Vector &vector);

    friend istream&operator>>(istream &is,Vector &vector);

    double operator[](int index) const;

    operator double*();
};
