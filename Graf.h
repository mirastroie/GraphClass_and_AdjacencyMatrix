#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#include <iostream>

class Graf{
protected:
    int N;

public:
    Graf();
    Graf(int);
    virtual ~Graf();
    Graf(const Graf&);
    friend std::istream &operator>>(std::istream&,Graf&);
    friend std::ostream &operator<<(std::ostream&,const Graf&);
    virtual void afisare_arce()=0;


};
#endif // GRAF_H_INCLUDED
