#ifndef GRAF_COMPLET_H_INCLUDED
#define GRAF_COMPLET_H_INCLUDED
#include "Graf.h"
#include <iostream>
class Graf_complet:virtual public Graf
{
 public:
    Graf_complet();
    Graf_complet(int);
    virtual ~Graf_complet();
    Graf_complet(const Graf_complet&);
    virtual Graf_complet& operator=(const Graf_complet&);
    friend std::istream&operator>>(std::istream&,Graf_complet&);
    friend std::ostream&operator<<(std::ostream&,const Graf_complet&);
    void afisare_arce();
};

#endif // GRAF_COMPLET_H_INCLUDED
