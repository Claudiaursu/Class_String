#include <iostream>
#include <string.h>
#include "String.h"
#include "Colectie_string.h"
using namespace std;


int main()
{
    /* ---MENIU--- */
    char comand;
    cout<<"Introduceti ce comanda doriti sa efectuati, dupa cum urmeaza: "<<endl;
    cout<<"u-> constructor cu parametru sir"<<endl;
    cout<<"v-> constructor cu parametru caracter"<<endl;
    cout<<"w-> constructor cu parametru obiect de tip String"<<endl;
    cout<<"a-> citire si afisare obiect         e-> atribuire string-string"<<endl;
    cout<<"b-> concatenare string-string        f-> atribuire string-caracter"<<endl;
    cout<<"d-> concatenare string-caracter"<<endl;
    cout<<"g-> concatenare caracter-string"<<endl;
    cout<<"h-> Verificari egalitate si neegalitate string-string  \t\t k-> semnele <,<=, >,>= pentru string-string"<<endl;
    cout<<"i-> Verificari egalitate si neegalitate string-caracter\t\t l-> semnele <,<=, >,>= pentru string-caracter"<<endl;
    cout<<"j-> Verificari egalitate si neegalitate caracter-string\t\t m ->semnele <,<=, >,>= pentru caracter-string"<<endl;
    cout<<"n-> length"<<endl;
    cout<<"o-> pos "<<endl;
    cout<<"p-> copy"<<endl;
    cout<<"q-> insert"<<endl;
    cout<<"r-> delete"<<endl;
    cout<<"s-> elimina toate aparitiile unui subsir dintr-un sir"<<endl;
    cout<<"t-> creeaza un tablou de obiecte, pe care le citeste de la tastatura, dupa le afiseaza"<<endl;
    cout<<"x-> iesire"<<endl;

    cin>>comand;

    while(comand!='x' && comand !='X')
    {
        switch(comand)
        {
        case 'a':
        {
            String a;
            a.setare();
            a.print_sir();
            break;
        }
        case 'u':
        {
            char aux[100];
            cout<<"Dati un sir care sa fie trimis ca parametru la constructor: ";
            cin>>aux;
            String a(aux);
            a.print_sir();
            break;
        }
        case 'v':
        {
            char x;
            cout<<"Dati un caracter care sa fie trimis ca parametru la constructor: "; cin>>x;
            String a(x);
            a.print_sir();
            break;
        }
        case 'w':
        {
            String a; cout<<"Dati un sir pe care il vom pune intr-un obiect, iar obiectul acesta va fi dat ca parametru constructorului :";
            cin>>a;
            String b(a);
            cout<<"Noul obiect: ";
            b.print_sir();
            break;
        }


        case 'e':
        {
            String b;
            cout<<"Dati un sir cu care vreti sa fie egal sirul din obiect iar functia urmatoare il va atribui ";
            char aux[100];
            cin>>aux;
            cout<<endl;
            b=aux;
            b.print_sir();
            break;
        }
        case 'f':
        {
            String c;
            cout<<"Dati un caracter cu care vreti sa fie egal sirul din obiect iar functia urmatoare il va atribui ";
            char a;
            cin>>a;
            cout<<endl;
            c=a;
            c.print_sir();
            break;
        }
        case 'b':
        {
            String a1, a2;
            cout<<"1: ";
            cin>>a1;
            cout<<"2: ";
            cin>>a2;
            String rez;
            rez=a1+a2;
            cout<<"Dupa concatenare: ";
            rez.print_sir();
            break;
        }
        case 'd' :
        {
            String b;
            cin>>b;
            char c;
            cout<<"Dati un caracter: ";
            cin>>c;
            String rez;
            rez= b+c;
            cout<<"Dupa concatenare: ";
            rez.print_sir();
            break;
        }
        case 'g' :
        {
            String b;
            char x;
            cout<<"Dati caracterul: ";
            cin>>x;
            cin>>b;
            String rez;
            rez=x+b;
            cout<<"Dupa concatenare: ";
            rez.print_sir();
            break;

        }
        case 'h' :
        {
            String s1,s2;
            cin>>s1;
            cin>>s2;
            if(s1==s2)
                cout<<"Sirurile sunt egale"<<endl;
            if(s1!=s2)
                cout<<"Sirurile nu sunt egale"<<endl;
            break;

        }
        case 'i' :
        {
            String s1;
            char x;
            cin>>s1;
            cout<<"Dati un caracter: ";
            cin>>x;
            if(s1==x)
                cout<<"Caracterul e egal cu sirul dat"<<endl;
            if(s1!=x)
                cout<<"Caracterul nu e egal cu sirul dat"<<endl;
            break;
        }
        case 'j' :
        {
            String w;
            char z;
            cout<<"Dati un caracter: ";
            cin>>z;
            cin>>w;
            if(z==w)
                cout<<"Caracterul e egal cu sirul dat"<<endl;
            if(z!=w)
                cout<<"Caracterul nu e egal cu sirul dat"<<endl;
            break;
        }
        case 'k' :
        {
            String s1,s2;
            cin>>s1;
            cin>>s2;
            if(s1>s2)
                cout<<"Sirul 1 e lexicografic mai mare decat sirul 2"<<endl;
            if(s1<s2)
                cout<<"Sirul 1 e lexicografic mai mic decat sirul 2"<<endl;
            if(s1>=s2)
                cout<<"Sirul 1 e lexicografic mai mare sau egal decat sirul 2"<<endl;
            if(s1<=s2)
                cout<<"Sirul 1 e lexicografic mai mic sau egal decat sirul 2"<<endl;
            break;
        }
        case 'l' :
        {
            String s1;
            char x;
            cin>>s1;
            cout<<"Dati un caracter: ";
            cin>>x;
            if(s1>x)
                cout<<"Sirul e lexicografic mai mare decat caracterul dat"<<endl;
            if(s1<x)
                cout<<"Sirul e lexicografic mai mic decat caracterul dat"<<endl;
            if(s1>=x)
                cout<<"Sirul e lexicografic mai mare sau egal decat caracterul dat"<<endl;
            if(s1<=x)
                cout<<"Sirul e lexicografic mai mic sau egal decat caracterul dat"<<endl;
            break;
        }
        case 'm' :
        {
            String s;
            char z;
            cout<<"Dati un caracter: ";
            cin>>z;
            cin>>s;
            if(z>s)
                cout<<"Caracterul dat e lexicografic mai mare decat sirul dat"<<endl;
            if(z<s)
                cout<<"Caracterul dat e lexicografic mai mic decat sirul dat"<<endl;
            if(z>=s)
                cout<<"Caracterul dat e lexicografic mai mare sau egal decat sirul dat"<<endl;
            if(z<=s)
                cout<<"Caracterul dat e lexicografic mai mic sau egal decat sirul dat"<<endl;
            break;
        }
        case 'n' :
        {
            String s;
            cin>>s;
            cout<<"Sirul dat are lungimea de "<<length(s)<<endl;
            break;
        }
        case 'o' :
        {
            String p1,p2;
            cin>>p1;
            cin>>p2;
            if(p1.pos(p2)!=-1)
                cout<<"Sirul 2 se gaseste in sirul 1 la pozitia "<<p1.pos(p2)<<endl;
            else
                cout<<"Sirul 2 nu se gaseste in sirul 1"<<endl;
            break;
        }

        case 'p' :
        {
            String p1,p2;
            cin>>p1;
            int index,nr;
            cout<<"Dati indexul de la care vreti sa copiati si numarul de litere pe care doriti sa il copiati ";
            cin>>index>>nr;
            p2=p1.copy_string(index,nr);
            cout<<endl<<p2;
            break;
        }
        case 'q' :
        {
            String a1,a2,rezultat;
            int index;
            cin>>a1;
            cout<<"Ce vreti sa inserati ";
            cin>>a2;
            cout<<"La ce index vreti sa inserati? ";
            cin>>index;
            rezultat=a1.insert_string(a2,index);
            cout<<rezultat;
            break;
        }
        case 'r' :
        {
            String s1,s2;
            int index,nr;
            cin>>s1;
            cout<<"De la ce index doriti sa stergeti si cate litere doriti sa stergeti? ";
            cin>>index>>nr;
            s2=s1.delete_string(index,nr);
            cout<<endl<<s2;
            break;

        }

        case 's' :
        {
            String x1,x2,rezultat_final;
            x1.setare();
            x2.setare();
            rezultat_final=delete_substr(x1,x2);
            cout<<endl<<rezultat_final;
            break;
        }
        case 't' :
        {
            Colectie_string tablou1;
            tablou1.create();
            break;
        }
        default:
        {
            cout<<"Introduceti doar caracterele indicate mai sus!"<<endl;
            break;
        }


        }

        cin>>comand;
    }



}
