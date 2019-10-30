#ifndef STRING_H
#define STRING_H

using namespace std;
#include <iostream>

class String
{
  char *denumire;
  int n; // lungimea sirului(cu tot cu caracterul '\0' )
public:
    String();
    String(int);
    String(char *); // constructor de initializare cu siruri pointate de char *
    String(const char); // constructor de initializare cu valoare de tip char
    String(const String&); // constructor de initializare cu un alt obiect de tip string
    ~String();

    void setare(); /// metoda publica de setat sirul
    void print_sir(); /// metoda publica pt afisat sirul si lungimea acestuia

    friend istream& operator>>(istream&, String&);
    friend ostream& operator<<(ostream&, String&);

    String& operator=(const String&);
    String& operator=(const char *);
    String& operator=(const char );
    char operator[](int);

    friend String operator+(const String&,const String&); ///concateneaza 2 obiecte (string-string)
    friend String operator+(const String&, char); /// varianta string-caracter
    friend String operator+(char, const String&); ///varianta caracter-string

    friend int operator==(const String&, const String&);
    friend int operator==(const String&, char);
    friend int operator==(char, const String&);

    friend int operator!=(const String&, const String&);
    friend int operator!=(const String&, char);
    friend int operator!=(char, const String&);

    friend int operator<(const String&, const String&);
    friend int operator<(const String&, char);
    friend int operator<(char, const String&);

    friend int operator<=(const String&, const String&);
    friend int operator<=(const String&, char);
    friend int operator<=(char, const String&);

    friend int operator>(const String&, const String&);
    friend int operator>(const String&, char);
    friend int operator>(char, const String&);

    friend int operator>=(const String&, const String&);
    friend int operator>=(const String&, char);
    friend int operator>=(char, const String&);

    friend int length(const String&);

    int pos(const String& );
    String copy_string (int, int);
    String copy_string2(int, int);
    String insert_string(const String&, int);
    String delete_string(int, int);

    friend String delete_substr(const String&, const String&);

};

#endif // STRING_H
