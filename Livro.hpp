#ifndef _LIVRO_LIBRY_
#define _LIVRO_LIBRY_

#include <string>
#include "Publicacao.hpp"
using namespace std;

class Livro: public Publicacao{
    string autores;
    int qtdeExemplares;
public: 
    Livro(const string& tit= string("def") , const string& ed = string("def"), 
        const int&  a = 0 , const int& cod = 0, const string& aut = string("def"),
        const int& qtde = 0):Publicacao(tit, ed , a , cod),
        autores(aut), qtdeExemplares(qtde){}
    Livro(const Livro&);
    ~Livro();
    string obterAutores();
    int obterNumExemplares();
    Livro& adExemplar(){qtdeExemplares++; return *this;}
    Livro& subExemplar(){qtdeExemplares--; return *this;}
    Livro& setarExemplares(int n){qtdeExemplares = n; return *this;}
    Livro& setarAutores(string s){autores = s; return *this;}
    Livro& operator++(int){qtdeExemplares++; return *this;}
    Livro& operator--(int){qtdeExemplares--; return *this;}
    Livro& mostrar();
    Livro& operator=(Livro&);
    bool operator==(Livro& p);
    friend ostream& operator<< (ostream&, Livro&);
    friend istream& operator>> (istream&, Livro&); 
};

#endif