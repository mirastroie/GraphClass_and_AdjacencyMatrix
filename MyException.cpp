#include "MyException.h"
#include <bits/stdc++.h>

///Nota: Intrucat string-ul nu este alocat pe heap, se face apel la destructorul clasei si se curata memoria automat
MyException::MyException(const std::string S, int value):value(value),s(S){}
const char* MyException::what()const throw()
    {

         return s.c_str();
    }
int MyException::number() const throw(){
        return value;
}
