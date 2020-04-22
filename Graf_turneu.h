#ifndef GRAF_TURNEU_H_INCLUDED
#define GRAF_TURNEU_H_INCLUDED
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
class Graf_turneu: public Graf_complet, public Graf_antisimetric{

  public:
    Graf_turneu();
    Graf_turneu(int);
    virtual ~Graf_turneu();
    Graf_turneu(const Graf_turneu&);
    virtual Graf_turneu operator=(const Graf_turneu&);
    friend std::istream&operator>>(std::istream&,Graf_turneu&);
    friend std::ostream&operator<<(std::ostream&,const Graf_turneu&);
    void afisare_arce();
};

#endif // GRAF_TURNEU_H_INCLUDED
