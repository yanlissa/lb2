#include <iostream>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

void testVector(Vector &u,Vector &v)
{
    cout<<"Vector:\n";
    cout<<"add:\n"<<u<<"+"<<v<<"="<<u+v<<endl;
    cout<<"sub:\n"<<u<<"-"<<v<<"="<<u-v<<endl;
    cout<<"dot product\n"<<u<<"*"<<v<<"="<<u*v<<endl;
    cout<<"const mul\n"<<2<<"*"<<u<<"*"<<3<<"="<<2*u*3<<endl;
}

void testCSLR(CSLRMatrix &cslr,Vector a,Vector b)
{
    cout<<"CSLR:\n";
    cout<<"matrix:"<<endl;
    cout<<cslr;
    cout<<"const mul:"<<2<<"*"<<"CSLRMatrix"<<"*"<<2<<"="<<endl;
    cout<<2*cslr*2;
    cout<<"vector mul:"<<"CSLRMatrix"<<"*"<<a<<"=";
    cout<<cslr*a<<endl;
    cout<<"---------"<<endl;

    cout<<"complicated 1:"<<endl;
    double comp=2*cslr*2*a*(a-b);
    cout<<comp<<endl;

    cout<<"complicated 2:"<<endl;
    cout<<-2*cslr*(a-3*b)+4*a<<endl;
}

int main()
{
    double c[]={1,-2,3,-1};
    Vector u=Vector(4,c);
    double coords[]={1,1,1,0};
    Vector v=Vector(4,coords);
    double ac[]={1,2,0,3,1};
    Vector a=Vector(5,ac);
    double bc[]={-1,2,3,5,-7};
    Vector b=Vector(5,bc);

    testVector(u,v);

    double adiag[]={1,3,1,2,3};
    double altr[]={1,0.8,1,2};
    int jptr1[]={0,1,1,1};
    int iptr1[]={0,0,0,2,3,4};

    CSLRMatrix cslr=CSLRMatrix(adiag,5,altr,jptr1,4,iptr1);

    testCSLR(cslr,a,b);

    Vector cer;
    cin>>cer;
    cout<<"vector v = "<<cer<<endl;
    return 0;
}
