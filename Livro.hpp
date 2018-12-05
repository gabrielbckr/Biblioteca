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
    void adExemplar(){qtdeExemplares++;}
    void subExemplar(){qtdeExemplares--;}
    Livro& operator++(int){qtdeExemplares++;}
    Livro& operator--(int){qtdeExemplares--;}
    Livro& operator=(Livro&);
    bool operator==(Livro& p);
};

#endif