#include "Colectie_string.h"
#include "String.h"
using namespace std;
#include <iostream>

Colectie_string :: Colectie_string()
{
    nr=0;
    tablou=NULL;
}

void Colectie_string :: create()
{
    cout<<"Cate obiecte de tip String doriti sa cititi si sa stocati? ";
    cin>>nr;

    tablou= new String[nr];
    for(int i=0; i<nr; i++)
    {
        tablou[i].setare();  //pentru fiecare string citim sirul de la tastatura, prin functia "setare"
    }
    cout<<"Colectia de stringuri este urmatoarea: "<<endl;
    for(int i=0; i<nr; i++)
    {
        tablou[i].print_sir();
    }
}
