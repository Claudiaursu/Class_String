#include "String.h"
using namespace std;
#include <iostream>
#include <string.h>

String :: String ()
{   //constructor fara parametrii
    denumire=NULL;
    n=0;
}

String :: String(int a)
{
    n=a;
    if(n==0)
        denumire=NULL;
    else
        denumire=new char[n]; //alocam spatiu cat pentru a caractere
}
String :: String (char *denum)
{
    denumire=new char[strlen(denum)+1];
    strcpy(denumire, denum);
    n=strlen(denum)+1; // consideram n lungimea sirului, care include si caracterul '\0'
}
String :: String (const char element)
{
    n=2;
    denumire= new char[2];
    denumire[0]=element;
    denumire[1]='\0';
}
String :: String (const String& ob)
{
    n=ob.n;
    denumire=new char[strlen(ob.denumire)+1];
    if(ob.denumire==NULL)
        denumire=NULL;
    else
        strcpy(denumire, ob.denumire);
}

String :: ~String()
{
    delete[] denumire;
}

void String :: setare()
{   // citim de la tastatura un sir de caractere, ii alocam memorie necesara, il stocam in char *, si salvam si lungimea sa
    cout<<"Dati un sir de caractere: ";
    char *aux= new char[100];
    cin>>aux;
    denumire= new char[strlen(aux)+1];
    strcpy(denumire,aux);
    n=strlen(aux) +1;
}

void String :: print_sir()
{   //afisarea sirului si a lungimii sale
    if(n!=0 && denumire!=NULL)
        cout<<"Sirul este: "<<denumire<<" cu lungimea de "<<n<<endl;
    if(n==0)
        cout<<"Sirul inca nu a fost initializat, lungimea sa este "<<n<<endl;
    if(n!=0 && denumire[0]=='\0')
        cout<<"Lungime de "<<n<<" si inca nu e initializat sirul"<<endl;
}

istream& operator>> (istream& in, String &ob)
{   //supraincarcarea operatorului de intrare (citim sirul de la tastatura)
    char aux[100];
    cout<<"Dati sirul: ";
    in>>aux;
    ob.denumire=new char[strlen(aux)+1];
    strcpy(ob.denumire, aux);
    ob.n=strlen(aux)+1;
    return in;
}

ostream& operator<< (ostream& out, String &ob)
{   //supraincarcarea operatorului de iesire (afisam denumirea si lungimea)
    if(ob.n!=0 && ob.denumire!=NULL)
        out<<"Sirul este "<<ob.denumire<<" cu lungime de "<<ob.n<<endl;
    if(ob.n==0)
        out<<"Sirul inca nu a fost initializat, lungimea sa este "<<ob.n<<endl;
    if(ob.n!=0 && ob.denumire==NULL)
        out<<"Lungime de "<<ob.n<<" si inca nu e initializat sirul"<<endl;

    return out;
}

String& String :: operator=(const String& ob)
{   // varianta in care atribuim un obiect intreg altui obiect deja creat
    if(this!=&ob)
    {
        denumire=new char[strlen(ob.denumire)+1];
        strcpy(denumire,ob.denumire);
        n=ob.n;

        return *this;
    }
}

String& String :: operator=(const char *sir)
{   //varianta string-string (unui obiect de tip string ii vom putea atribui un sir de caractere)
    if(denumire!=sir)
    {
        denumire=new char[strlen(sir)+1];
        strcpy(denumire,sir);
        n=strlen(sir)+1;
        return *this;
    }
}

String& String :: operator=(const char a)
{   //varianta string-caracter de atribuire (unui obiect de tip string ii vom putea atribui un caracter)
    denumire=new char[1];
    denumire[0]=a;
    n=1;
    return *this;
}

char String :: operator[](int a)  ///returnam caracterul stocat la indicele a
{
    return denumire[a];
    if(a<0 || a>=n)
    {
        cout<<"Ati depasit lungimea sirului"<<endl;
    }
}

String operator+(const String& ob1,const String& ob2)
{
    // concatenare intre 2 obiecte de tip string, iar noul sir rezultat este stocat intr-un nou obiect, pe care il returnam
    String rez;
    rez.n=ob1.n + ob2.n -1;
    rez.denumire= new char[ rez.n ];
    char aux[100];
    strcpy(aux,ob1.denumire);
    strcat(aux,ob2.denumire);
    strcpy(rez.denumire, aux);

    return rez;
}

String operator+(const String& ob, char a)
{
    /* concatenare intre un sir de caractere (obiect de tip string, primit ca parametru) si un caracter,
      iar noul sir rezultat este stocat intr-un nou obiect, pe care il returnam */
    String rez;
    rez.n=ob.n+1;
    rez.denumire=new char[rez.n];
    strcpy(rez.denumire, ob.denumire);
    rez.denumire[ob.n-1]=a;
    return rez;
}

String operator+(char a, const String& ob)
{
    /* concatenare intre un caracter si un sir de caractere (obiect de tip string primit ca parametru),
      iar noul sir rezultat este stocat intr-un nou obiect, pe care il returnam */
    String rez;
    rez.n=ob.n+1;
    rez.denumire=new char [rez.n];
    rez.denumire[0]=a;
    rez.denumire[1]='\0';
    strcat(rez.denumire,ob.denumire);
    return rez;
}

int operator==(const String& a, const String& b)
{
    if(strcmp(a.denumire, b.denumire)==0)
        return 1; //sunt la fel
    else
        return 0; //diferite
}
int operator==(const String& ob, char a)
{
    if(ob.n==2 && ob.denumire[0]==a)
        return 1;
    else
        return 0;
}
int operator==(char a, const String& ob)
{
    if(ob.n==2 && ob.denumire[0]==a)
        return 1;
    else
        return 0;
}

int operator!=(const String& a, const String& b)
{
    if(strcmp(a.denumire, b.denumire)==0)
        return 0; //sunt la fel
    else
        return 1;
}
int operator!=(const String& ob, char a)
{
    if(ob.n==2 && ob.denumire[0]==a)
        return 0;
    else
        return 1; //nu sunt egale caracterele
}
int operator!=(char a, const String& ob)
{
    if(ob.n==2 && ob.denumire[0]==a)
        return 0;
    else
        return 1;
}

int operator<(const String& a, const String& b)
{
    if( strcmp(a.denumire,b.denumire)<0)
        return 1;
    else
        return 0;
}
int operator<(const String& ob, char a)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(ob.denumire, aux)<0)
        return 1;
    else
        return 0;
}
int operator<(char a, const String& ob)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(aux, ob.denumire)<0)
        return 1;
    else
        return 0;
}

int operator<=(const String& a, const String& b)
{
    if(strcmp(a.denumire, b.denumire)<0 || strcmp(a.denumire, b.denumire)==0)
        return 1;
    else
        return 0;
}
int operator<=(const String& ob, char a)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(ob.denumire, aux)<0 || strcmp(ob.denumire, aux)==0 )
        return 1;
    else
        return 0;
}
int operator<=(char a, const String& ob)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(aux, ob.denumire)<0 || strcmp(aux, ob.denumire)==0 )
        return 1;
    else
        return 0;
}

int operator>(const String& a, const String& b)
{
    if( strcmp(a.denumire,b.denumire)>0)
        return 1;
    else
        return 0;
}
int operator>(const String& ob, char a)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(ob.denumire, aux)>0)
        return 1;
    else
        return 0;
}
int operator>(char a, const String& ob)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(aux, ob.denumire)>0 )
        return 1;
    else
        return 0;
}

int operator>=(const String& a, const String& b)
{
    if( strcmp(a.denumire,b.denumire)>0 || strcmp(a.denumire,b.denumire)==0)
        return 1;
    else
        return 0;
}
int operator>=(const String& ob, char a)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(ob.denumire, aux)>0 || strcmp(ob.denumire, aux)==0)
        return 1;
    else
        return 0;
}
int operator>=(char a, const String& ob)
{
    char aux[1];
    aux[0]=a;
    aux[1]='\0';
    if(strcmp(aux, ob.denumire)>0 || strcmp(aux, ob.denumire)==0 )
        return 1;
    else
        return 0;
}

int length(const String& ob)
{   // functie care returneaza lungimea sirului stocat in obiectul primit ca parametru
    int lungime=0, i=0;
    while(ob.denumire[i]!='\0')
    {
        lungime++;
        i++;
    }
    lungime++; // adunam si caracterul '\0' la lungimea sirului

    return lungime;
}

int String :: pos(const String& sir)
{
    // returnam indicele la care se gaseste denumirea din obiectul dat ca parametru, daca se regaseste in obiectul apelat
    int s1=strlen(denumire);
    int s2=strlen(sir.denumire);
    int i,j,index;
    int def=-1; //returnam in mod default -1 daca nu gasim subsirul
    for(i=0; i<=s1; i++)
    {
        for(j=0; j<=s2; j++)
        {
            index=i;
            if(denumire[i+j]!= sir.denumire[j])
                break;
            if(j==s2)
                return index;
        }
    }
    return def;
}

String String :: copy_string(int index, int nr)
{
    /* Aceasta functie copiaza din sirul obiectului apelat nr litere, incepand de la indexul dat
      si stocheaza noul sir intr-un nou obiect, pe care il returnam */
    String rez;
    rez.denumire=new char[nr+1];
    int j=0;

    int i=index;
    while(denumire[i]!='\0' && j<nr)
        rez.denumire[j++]=denumire[i++];

    rez.n=j+1;
    return rez;
}

String String :: insert_string( const String& ob, int index)
{
    /*Aceasta functie insereaza sirul din cadrul obiectului primit ca parametru in sirul stocat in cadrul obiectului apelat,
     incepand de la indicele dat. Returnam un nou obiect de tip String in care am stocat noul rezultat*/
    String rez;
    rez.denumire=new char[strlen(ob.denumire)+strlen(denumire) + 1];
    rez.n=strlen(ob.denumire)+strlen(denumire) + 1;

    int j=0;
    char aux[100];
    for(int i=index; i<strlen(denumire); i++)
    {
        aux[j]=denumire[i];
        j++;
    }
    aux[j]='\0';
    denumire[index]='\0';
    strcat(denumire, ob.denumire);
    strcpy(rez.denumire,denumire);
    strcat(rez.denumire, aux);
    return rez;
}

String String :: delete_string(int index, int nr)
{
    // aceasta functie sterge din sirul obiectului apelat nr litere, incepand de la indexul dat
    // returnam un nou obiect de tip String in care am stocat noul rezultat, pentru a nu il modifica pe cel apelat
    String rez;
    rez.n=strlen(denumire)-nr +1;
    rez.denumire= new char[rez.n];

    int j=0;
    char rest[100];
    for(int i=index+nr; i<strlen(denumire); i++)
    {
        rest[j]=denumire[i];
        j++;
    }
    rest[j]='\0';
    char aux[100];
    strcpy(aux, denumire);
    aux[index]='\0';
    strcat(aux, rest);
    strcpy(rez.denumire, aux);

    return rez;
}

String delete_substr(const String& ob1, const String& ob2)
{
    // aceasta functie sterge din ob1 toate aparitiile sirului ob2 (ambele obiecte primite ca parametru)
    // returnam un obiect de tip String pentru a nu le modifica pe cele 2 primite ca parametrii
    String rez;
    rez.denumire= new char[strlen(ob1.denumire)]; //cazul maxim
    char copie1[100];
    strcpy(copie1, ob1.denumire);
    char *p=strstr(copie1, ob2.denumire);
    if(p==NULL)
        strcpy(rez.denumire, ob1.denumire);
    else
    {
        while(p)
        {
            strcpy(p,p+strlen(ob2.denumire));
            p=strstr(p,ob2.denumire);
        }
        strcpy(rez.denumire,copie1);
        rez.n=strlen(rez.denumire)+1;

    }
    return rez;
}
