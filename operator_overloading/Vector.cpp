#include "Vector.h"
#include "cmath"

double Vector::length() {
    double lenSquared=0;
    for (int i=0;i<n;i++) lenSquared+=dest[i]*dest[i];
    return sqrt(lenSquared);
}

int Vector::getDimension() const {
    return n;
}

Vector Vector::operator+(const Vector &vector) const {
    if (n!=vector.n) throw IncompatibleDimException();
    double d[n];
    for (int i=0;i<n;i++) d[i]=dest[i]+vector.dest[i];
    return Vector(n,d);
}

Vector Vector::operator+() {
    return Vector(n,dest);
}

Vector Vector::operator-(const Vector &vector)const{
    if (n!=vector.n) throw IncompatibleDimException();
    double d[n];
    for (int i=0;i<n;i++) d[i]=dest[i]-vector.dest[i];
    return Vector(n,d);
}

Vector Vector::operator-(){
    double d[n];
    for (int i=0;i<n;i++) d[i]=-dest[i];
    return Vector(n,d);
}

Vector& Vector::operator+=(const Vector &vector){
    if (n!=vector.n) throw IncompatibleDimException();
    for (int i=0;i<n;i++) dest[i]+=vector.dest[i];
    return *this;
}

Vector& Vector::operator-=(const Vector &vector){
    if (n!=vector.n) throw IncompatibleDimException();
    for (int i=0;i<n;i++) dest[i]-=vector.dest[i];
    return *this;
}

Vector Vector::operator*(double value)const{
    double d[n];
    copy(dest,dest+n,d);
    for (int i=0;i<n;i++) d[i]*=value;
    return Vector(n,d);
}

double Vector::operator*(const Vector &vector)const{
    if (n!=vector.n) throw IncompatibleDimException();
    double res=0;
    for (int i=0;i<n;i++) res+=dest[i]*vector.dest[i];
    return res;
}

double Vector::operator[](int index) const{
    if (index<n && index>=0) return dest[index];
    throw OutOfRangeException();
}

ostream &operator<<(ostream &os, const Vector &vector) {
    os<<"(";
    for (int i=0;i<vector.n-1;i++){
        os<<vector.dest[i]<<",";
    }
    os<<vector.dest[vector.n-1]<<")";
    return os;
}

istream& operator>>(istream &is,Vector &vector){
    cout<<"enter dimension"<<endl;
    is>>vector.n;
    if (vector.n<0) throw IncompatibleDimException();
    cout<<"enter coordinates of vector"<<endl;
    delete[](vector.dest);
    vector.dest=new double[vector.n];
    for (int i=0;i<vector.n;i++) is>>vector.dest[i];
    return is;
}

Vector& Vector::operator=(const Vector &vector){
    if (this!=&vector){
        n=vector.n;
        double *d=new double[n];
        copy(vector.dest,vector.dest+n,d);
        delete[](dest);
        dest=d;
    }
    return *this;
}

Vector operator*(double value,const Vector &vector){
    return vector*value;
}

Vector::operator double*() {
    return dest;
}

Vector::Vector(const Vector &vector):n(vector.n){
    dest=new double[n];
    copy(vector.dest,vector.dest+n,dest);
}
