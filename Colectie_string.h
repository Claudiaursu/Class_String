#ifndef COLECTIE_STRING_H
#define COLECTIE_STRING_H

#include "String.h"
using namespace std;
#include <iostream>

class String;
class Colectie_string
{
    String *tablou;
    int nr;
    public:
        Colectie_string();
        void create();
        friend void setare();     //functii din clasa String, prietene pentru a putea citi stringurile de la tastatura
        friend void print_sir(); // si a le putea afisa

};

#endif // COLECTIE_STRING_H
