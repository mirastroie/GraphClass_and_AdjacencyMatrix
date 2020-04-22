#include "Graf_antisimetric.h"
#include <bits/stdc++.h>
#include <iostream>
#include "MyException.h"
///se apeleaza constructorul matrix pentru care matricea e de forma NXN si are M celule egale cu 1 - corespondenta a M muchii
Graf_antisimetric::Graf_antisimetric():Graf(1),matrix(1,0,0),M(0) {}
Graf_antisimetric::Graf_antisimetric(int N,int M):Graf(N),matrix(N,M,0),M(M) {
  if(M>N*(N-1)/2)
      throw(MyException("Eroare de construire a obiectului graf antisimetric",7));
}
Graf_antisimetric::~Graf_antisimetric()
{
    M=0;
    std::cout<<"Destructor graf antisimetric";
}

Graf_antisimetric::Graf_antisimetric(const Graf_antisimetric&old):Graf(old),matrix(old.matrix),M(old.M) {}

Graf_antisimetric& Graf_antisimetric::operator=(const Graf_antisimetric&old)
{


    if(this==&old)
        return *this;
    N=old.N;
    M=old.M;
    this->matrix=old.matrix;
    return *this;
}

Graf_antisimetric Graf_antisimetric::PartialAssignment(const Graf_antisimetric&old)
{
    if(this==&old)
        return *this;
    ///se apeleaza supraincarcarea operatorului de atribuire a clasei Matrice
    this->matrix=old.matrix;
    M=old.M;
    return *this;

}
std::istream &operator>>(std::istream& in,Graf_antisimetric&old)
{


    in>>(Graf&)old;
    std::cout<<"Sa se dea numarul de muchii: \n";
    in>>old.M;
    try{
       in>>old.matrix;
       if(old.matrix.get_n()!=old.matrix.get_m() || (old.matrix.get_n()==old.matrix.get_m() && old.matrix.get_n()!=old.N))
          throw(MyException("Matricea nu corespunde grafului pe care vrei sa il introduci",8));

    }
    catch(MyException&e){
          throw;}
    ///Individualizarea clasei Graf_antisimetric consta in proprietatea urmatoare: daca exista arc intre (x,y), atunci
    ///cu siguranta nu va exista arc intre (y,x). Trebuie verificata asadar aceasta conditiei si aruncata o exceptie in
    ///cazul in care input-ul nu respecta conditia impusa.
    if(old.matrix.anti_simetrie()==false)
        throw(MyException("Hopa! Matricea data nu reprezinta un graf antisimetric!",1));

    return in;
}
std::ostream &operator<<(std::ostream&out, const Graf_antisimetric&old)
{
    out<<(Graf&)old;
    out<<"Nr de muchii : "<<old.M<<"\n";
    out<<old.matrix;
    return out;
}
void Graf_antisimetric::afisare_arce()
{
    std::cout<<"Arcele sunt:\n";
    for(int i=0; i<matrix.get_n(); i++)
        for(int j=0; j<matrix.get_n(); j++)
            if(matrix.get(i,j))
                std::cout<<i<<" "<<j<<"\n";

}
