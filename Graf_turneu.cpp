#include "Graf_turneu.h"
#include <bits/stdc++.h>
#include <iostream>
#include "MyException.h"

///cand suntem in interiorul constructorului graf_turneu, most-derived class
///este clasa graf_turneu si prin urmare, constructorul acesteia este responsabil
///pentru initializarea clasei de baza;
Graf_turneu::Graf_turneu():Graf_complet(2),Graf_antisimetric(2,1){}
Graf_turneu::Graf_turneu(int N):Graf(N),Graf_complet(N),Graf_antisimetric(N,N*(N-1)/2){}
Graf_turneu::Graf_turneu(const Graf_turneu&old):Graf(old),Graf_complet(old),Graf_antisimetric(old){}
Graf_turneu::~Graf_turneu(){std::cout<<"Destructor Graf turneu\n";}
Graf_turneu Graf_turneu::operator=(const Graf_turneu&old)
{
      std::cout<<"Operator = in graf turneu\n";
      if(this==&old)return *this;
      Graf_complet::operator=(old);
      Graf_antisimetric::PartialAssignment(old);
      return *this;
}
std::istream &operator>>(std::istream&in,Graf_turneu&old)
{

    in>>(Graf_complet&)old;
    try{
    in>>(Graf_antisimetric&)old;
       if(old.M!=old.N*(old.N-1)/2)
        throw(MyException("Hopa! Graful turneu nu poate fi initializat! Inputul este gresit!",2));
    }
    catch(MyException&e)
    {
        throw(MyException("Hopa! Graful turneu nu poate fi initializat! Inputul este gresit!",2));
    }
    if(old.matrix.turneu()==false)
        throw(MyException("Hopa! Graful turneu nu poate fi initializat! Inputul este gresit!",10));
    return in;
}
std::ostream &operator<<(std::ostream&out,const Graf_turneu&old)
{


    out<<(Graf_antisimetric&)old;
    return out;
}
void Graf_turneu::afisare_arce()
{

     Graf_antisimetric::afisare_arce();
}
