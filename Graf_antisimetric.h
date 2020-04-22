#ifndef GRAF_ANTISIMETRIC_H_INCLUDED
#define GRAF_ANTISIMETRIC_H_INCLUDED
#include "Graf.h"
#include "Matrice.h"
class Graf_antisimetric: virtual public Graf{
protected:
   Matrice matrix;
   int M;
   public:
      Graf_antisimetric();
      Graf_antisimetric(int,int);
      virtual ~Graf_antisimetric();
      Graf_antisimetric(const Graf_antisimetric&);
      virtual Graf_antisimetric &operator=(const Graf_antisimetric&);
      Graf_antisimetric PartialAssignment(const Graf_antisimetric&);
      friend std::istream &operator>>(std::istream&,Graf_antisimetric&);
      friend std::ostream &operator<<(std::ostream&, const Graf_antisimetric&);
      void afisare_arce();

};


#endif // GRAF_ANTISIMETRIC_H_INCLUDED
