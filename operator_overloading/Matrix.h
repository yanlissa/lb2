#pragma once

#include <iostream>
#include "Vector.h"

using namespace std;

class CSLRMatrix
{
private:
    double *adiag;
    double *altr;
    int *jptr,*iptr;
    int dimension,nonZeroElements;
    double isNotZero(int i,int j)const{
        for (int k = iptr[i]; k < iptr[i + 1]; k++) {
            if (jptr[k]==j) return altr[k];
        }
        return 0.0;
    }
public:
    CSLRMatrix(double *adiag, int n, double *altr, int *jptr, int altrSize, int *iptr): dimension(n){
        this->adiag=new double[n];
        this->altr=new double[altrSize];
        this->jptr=new int[altrSize];
        this->iptr=new int[n+1];

        copy(adiag,adiag+n,this->adiag);
        copy(altr, altr + altrSize, this->altr);
        copy(jptr, jptr + altrSize, this->jptr);
        copy(iptr,iptr+n+1,this->iptr);

        nonZeroElements= n+2*altrSize;
    }
    virtual ~CSLRMatrix(){
        delete[](adiag);
        delete[](altr);
        delete[](jptr);
        delete[](iptr);
    }

    CSLRMatrix()= default;

    friend ostream &operator<<(ostream &os,const CSLRMatrix &cslr);

    CSLRMatrix&operator=(const CSLRMatrix &cslr);

    friend istream&operator>>(istream &is,CSLRMatrix &cslr);

    int getDimension();

    int getNonZerElementsNumber();

    Vector operator*(const Vector &vector)const;

    CSLRMatrix operator*(double value)const;

    friend CSLRMatrix operator*(double value,const CSLRMatrix &matrix);
};
