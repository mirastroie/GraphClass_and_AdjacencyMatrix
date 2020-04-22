#include <iostream>
#include "Matrice.h"
#include "Graf.h"
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include "Graf_turneu.h"
#include "MyException.h"
#include <vector>
using namespace std;

///Nota destructori: Intrucat doar matricea a fost declarata dinamic, doar clasa Matrice
///a avut nevoie de o implementare propriu-siza a destructorului pentru a elibera zona de
///memorie folosita si a evita memory leak. Desi clasa graf turneu are in compozitie un
/// obiect Matrice, destructorul acestei clase face trimitere din default catre constructorul
/// clasei Matrice, zona de memorie fiind eliberata fara alte complicatii. Destructori
///celorlalte clase  reduc implementarea la afisarea unui mesaj corespunzator -  alt cod
///nu este necesar, intrucat aceste clase nu au  variabile declarate dinamic. O alta nota
///legata de destructori face referire la natura lor virtuala, care asigura faptul ca, in urma upcastingului
/// unui pointer de tip derivata, zona de memorie este eliberata corespunzator, fiind chemati atat destructorii bazei,
///cat si cei ai derivatei.
void citire()
{
    vector <Graf*> object;
    int n,x;
    cin>>n;
    try
    {
        for(int i=0; i<n; i++)
        {
            cout<<"Complet(1), Antisimetric(2) sau  Turneu(3)?\n";
            cin>>x;
            if(x!=1 &&x!=2 && x!=3)
                throw(MyException("Input gresit",0));
            cin.get();
            switch(x)
            {
            case 1:
            {
                ///trebuie creat un bloc; atfel variabilele declarate nu au un scop => eroare
                Graf_complet*c=new Graf_complet;
                cout<<"Introdu complet\n";
                cin>>*c;
                object.push_back(c);

            }
            break;
            case 2:
            {
                Graf_antisimetric* an=new Graf_antisimetric;
                cout<<"Introdu antisimetric\n";
                try
                {
                    cin>>*an;
                }
                catch(MyException &e)
                {
                    throw; ///O rearuncam in exterior
                }
                object.push_back(an);

            }
            break;
            case 3:
            {
                Graf_turneu*t=new Graf_turneu;
                cout<<"Introdu turneu\n";
                try
                {
                    cin>>*t;
                }
                catch(MyException &e)
                {
                    throw;
                }
                object.push_back(t);

            }
            break;
            }
        }
    }
    catch(MyException &e)
    {
        cout<<e.what()<<"\n";
    }
    for(auto &it: object)
    {

        if(Graf_turneu*t=dynamic_cast<Graf_turneu*>(it))
            cout<<*t<<"\n";
        else if(Graf_complet*c=dynamic_cast<Graf_complet*>(it))
            cout<<*c<<"\n";
        else  if(Graf_antisimetric*an=dynamic_cast<Graf_antisimetric*>(it))
            cout<<*an<<"\n";

    }


    for(auto &it: object)
        delete it;

    object.clear();
    object.shrink_to_fit();
}
///Functia de mai jos ilustreaza functionalitatea aruncarii exceptiilor in constructori
void exceptii()
{
    try
    {

        Graf_complet(-2);
        ///nici nu mai ajunge sa construiasca urmatoarele obiecte, deoarece
        ///este aruncata exceptia de constructorul clasei graf_complet
        Graf_antisimetric(2,5);

    }
    catch(MyException&e)
    {
        cout<<e.what();
    }
}
int main()
{
    citire();
    ///exceptii();
    return 0;
}
