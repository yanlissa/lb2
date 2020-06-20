#include "Matrix.h"
#include "Vector.h"

ostream &operator<<(ostream &os, const CSLRMatrix &cslr){
    double isNotZero;
    for (int i=0;i<cslr.dimension;i++){
        os<<"(\t";
        for (int j=0;j<cslr.dimension;j++){
            if (i<j){
                if (cslr.jptr[cslr.iptr[j]]<j && (isNotZero=cslr.isNotZero(j,i))) os<<isNotZero<<"\t";
                else os<<0<<"\t";
            } else if(i>j){
                if (cslr.jptr[cslr.iptr[i]]<i && (isNotZero=cslr.isNotZero(i,j))) os<<isNotZero<<"\t";
                else os<<0<<"\t";
            } else os<<cslr.adiag[i]<<"\t";
        }
        os<<")"<<endl;
    }
    return os;
}

CSLRMatrix& CSLRMatrix::operator=(const CSLRMatrix &cslr){
    if (this!=&cslr){
        delete[](adiag);
        delete[](altr);
        delete[](jptr);
        delete[](iptr);

        dimension=cslr.dimension;
        nonZeroElements=cslr.nonZeroElements;

        int m=(nonZeroElements-dimension)/2;

        adiag=new double[dimension];
        altr=new double[m];
        jptr=new int[m];
        iptr=new int[dimension+1];

        copy(cslr.adiag,cslr.adiag+dimension,adiag);
        copy(cslr.altr,cslr.altr+m,altr);
        copy(cslr.jptr,cslr.jptr+m,jptr);
        copy(cslr.iptr,cslr.iptr+m,iptr);

    }
    return *this;
}

istream& operator>>(istream &is,CSLRMatrix &cslr){
    delete[](cslr.adiag);
    delete[](cslr.altr);
    delete[](cslr.jptr);
    delete[](cslr.iptr);
    int m,i;
    cout<<"enter dimension"<<endl;
    is>>cslr.dimension;
    if (cslr.dimension<2) throw IncompatibleDimException();
    cout<<"enter diagonal elements"<<endl;
    cslr.adiag=new double[cslr.dimension];
    for (i=0;i<cslr.dimension;i++){
        is>>cslr.adiag[i];
    }
    cout<<"enter altr size"<<endl;
    is>>m;
    if (m<0) throw OutOfRangeException();
    cout<<"enter altr"<<endl;
    cslr.altr=new double[m];
    for (i=0;i<m;i++){
        is>>cslr.altr[i];
    }
    cout<<"enter jptr"<<endl;
    cslr.jptr=new int[m];
    for (i=0;i<m;i++){
        is>>cslr.jptr[i];
    }
    cout<<"enter iptr"<<endl;
    cslr.iptr=new int[cslr.dimension+1];
    for (i=0;i< cslr.dimension + 1; i++){
        is>>cslr.iptr[i];
    }
    cslr.nonZeroElements=cslr.dimension+2*m;
    return is;
}

Vector CSLRMatrix::operator*(const Vector &vector)const{
    if (dimension!=vector.getDimension()) throw IncompatibleDimException();
    double z[dimension];
    for (int i=0;i<dimension;i++) z[i]=adiag[i]*vector[i];
    for (int i=0;i<dimension;i++){
        for (int j=iptr[i];j<iptr[i+1];j++){
            z[i]+=vector[jptr[j]]*altr[j];
            z[jptr[j]]+=vector[i]*altr[jptr[j]];
        }
    }
    return Vector(dimension,z);
}

CSLRMatrix CSLRMatrix::operator*(double value)const{
    double diag[dimension];
    int m=(nonZeroElements-dimension)/2;
    double other[m];
    for (int i=0;i<dimension;i++){
        diag[i]=adiag[i]*value;
    }
    for (int i=0;i<m;i++){
        other[i]=altr[i]*value;
    }
    return CSLRMatrix(diag,dimension,other,jptr,m,iptr);
}

CSLRMatrix operator*(double value,const CSLRMatrix &matrix){
    return matrix*value;
}

int  CSLRMatrix::getNonZerElementsNumber(){
    return nonZeroElements;
}

int CSLRMatrix::getDimension() {
    return dimension;
}
