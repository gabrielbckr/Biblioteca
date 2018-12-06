#ifndef _LIVRO_LIBRY_
#define _LIVRO_LIBRY_

#include <string>
#include "Publicacao.hpp"
using namespace std;

class Livro: public Publicacao{
    string autores;
    int qtdeExemplares;
public:
    Livro(string tit, string ed, int  a , int cod, string aut,
          int qtde = 0):Publicacao(tit, ed , a , cod),
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
    Livro& operator=(Livro&);
    bool operator==(Livro& p);
    friend ostream& operator<< (ostream&, Livro&);
    friend istream& operator>> (istream&, Livro&); 
};

#endif