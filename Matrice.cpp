#include "Matrice.h"
#include <bits/stdc++.h>
#include <iostream>
#include "MyException.h"
Matrice::Matrice()
{
    n=MAX_SIZE;
    m=MAX_SIZE2;
    a=new int*[n];
    for(int i=0; i<n; i++)
        a[i]=new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=0;

}
Matrice::Matrice(int n, int m):n(n),m(m)
{

    a=new int*[n];
    for(int i=0; i<n; i++)
        a[i]=new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=0;

}
///pune de M ori valoarea value in matrice, tinand seama de conditia de anti simetrie;
///matricea se face patratica si se respecta proprietatea de antisimetrie
Matrice::Matrice(int n,int M, int var):n(n),m(n)
{
    a=new int*[n];
    for(int i=0; i<n; i++)
        a[i]=new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=0;

    int count_occ=0;
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(count_occ<M)
            {
                a[i][j]=1;
                count_occ++;
            }
}
Matrice:: Matrice(const Matrice &old): n(old.n),m(old.m)
{
    a=new int*[n];
    for(int i=0; i<n; i++)
        a[i]=new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=old.a[i][j];
}
Matrice::~Matrice()
{
    std::cout<<"Destructor matrice\n";
    for(int i=0; i<n; i++)
        delete []a[i];
    delete []a;
}
std::istream &operator>>(std::istream&in,Matrice &old)
{
    ///pentru a preveni memory leak, eliberam zona de memorie pe care am folosit-o
    for(int i=0; i<old.n; i++)
        delete []old.a[i];
    delete []old.a;
    std::cout<<"Introdu N-ul: \n";
    in>>old.n;
    std::cout<<"Introdu M-ul: \n";
    in>>old.m;
    old.a=new int*[old.n];
    for(int i=0; i<old.n; i++)
        old.a[i]=new int[old.m];
    std::cout<<"Introdu matricea: \n";
    for(int i=0; i<old.n; i++)
        for(int j=0; j<old.m; j++)
            in>>old.a[i][j];
    return in;
}

std::ostream&operator<<(std::ostream&out,const Matrice &old)
{
    out<<"Matricea este: \n";
    for(int i=0; i<old.n; i++)
    {

        for(int j=0; j<old.m; j++)
        {
            out<<old.a[i][j]<<" ";
        }
        out<<"\n";
    }
    return out;
}
Matrice& Matrice::operator=(const Matrice&old)
{
    if(this==&old)
        return *this;
    ///se dezaloca memoria folosita pentru prevenirea memory leak
    for(int i=0; i<n; i++)
        delete []a[i];
    delete []a;

    n=old.n;
    m=old.m;
    a=new int*[n];
    for(int i=0; i<n; i++)
        a[i]=new int[m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            a[i][j]=old.a[i][j];
    return *this;

}
int Matrice::get_n()const
{
    return n;
}
int Matrice::get_m()const
{
    return m;
}
void Matrice::setter(int p)
{
    n=p;
    m=p;
}
int Matrice::get(int i, int j)const
{
    return a[i][j];
}
bool Matrice::anti_simetrie()const
{

    ///prima oara verificam daca matricea data este matrice de adiacenta
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            if(a[i][j]!=0 && a[i][j]!=1)
                return false;
            if(a[i][i]==1)
                return false;
        }

    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if(a[i][j]==a[j][i] && a[i][j]==1)
                return false;
    return true;
}

bool Matrice::turneu()const
{
    for(int i=1; i<n; i++)
        for(int j=0; j<i; j++)
            if((a[i][j]|| a[j][i])==0)
                return false;
    return true;
}




