#include "Graf_complet.h"
#include <bits/stdc++.h>
#include "MyException.h"

///Constructori si destructor
Graf_complet::Graf_complet():Graf(2) {}
Graf_complet::Graf_complet(int N):Graf(N)
{
    if(N<2)
        throw(MyException("Eroare de construire a obiectului graf complet",5));
}
Graf_complet:: ~Graf_complet()
{
    std::cout<<"Destructor Graf complet\n";
}
///se face trimitere la CC din clasa de baza
Graf_complet::Graf_complet(const Graf_complet&old):Graf(old) {}

///Operators overloading
Graf_complet& Graf_complet::operator=(const Graf_complet&old)
{

    if(this==&old)
        return *this;
    N=old.N;
    return *this;
}
std::istream &operator>>(std::istream&in,Graf_complet&old)
{

    in>>(Graf&)old; ///upcasting
    return in;
}
std::ostream&operator<<(std::ostream&out,const Graf_complet&old)
{

    out<<(Graf&)old;
    return out;

}
void Graf_complet::afisare_arce()
{
    std::cout<<"Graful tau este complet. Asadar, avem arc/muchie intre oricare 2 noduri.\n";
}
