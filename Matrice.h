#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include <iostream>

class Matrice{
    protected:
      int n,m;
      int **a;
      const int MAX_SIZE=100;
      const int MAX_SIZE2=100;
  public:
      Matrice();
      Matrice(int,int);
      Matrice(int , int ,int);
      Matrice(const Matrice&);
      ~Matrice();
      int get_n()const;
      int get_m()const;
      void setter(int);
      int get(int,int)const;
      Matrice &operator=(const Matrice&);
      void citire(int, int);
      bool anti_simetrie()const;
      bool turneu()const;
      friend std::ostream&operator<<(std::ostream&,const Matrice&);
      friend std::istream&operator>>(std::istream&, Matrice&);

};



#endif // MATRICE_H_INCLUDED
