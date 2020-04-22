#include "Graf.h"
#include <bits/stdc++.h>
#include <iostream>
#include "MyException.h"
///Constructori si destructori
Graf::Graf():N(1) {}
Graf::Graf(int N):N(N)
{
    if(N<0)
        throw(MyException("Eroare de construire a obiectului graf",6));
}
Graf::~Graf()
{
    std::cout<<"Destructor graf\n";
    N=1;
}
///CC
Graf::Graf(const Graf& old):N(old.N) {} ///CC
std::istream &operator>>(std::istream&in, Graf &old)
{
    std::cout<<"Introdu numarul de noduri: \n";
    in>>old.N;
    return in;
}
std::ostream &operator<<(std::ostream&out, const Graf&old)
{
    out<<"Numarul de noduri este: \n"<<old.N<<"\n";
    return out;
}

