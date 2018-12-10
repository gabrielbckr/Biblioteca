#ifndef _PUBLIC_LIBRY_
#define _PUBLIC_LIBRY_

#include <string>
#include <iostream>

using namespace std;

class Publicacao{
    string titulo, editora;
    int ano, codPublicacao;
public:
    Publicacao(const string& t = string("def"), const string& ed = string("def"),
                const int& a = 0, const int& cod = 0):
                titulo(t), editora(ed), ano(a), codPublicacao(cod){};
    Publicacao(const Publicacao&);
    virtual ~Publicacao();
    int obterAno() const {return ano;}
    int obterCodigo() const {return codPublicacao;}
    string obterTitulo() const {return titulo;}
    string obterEditora() const {return editora;}
    Publicacao& setarCodigo(int n){codPublicacao = n; return *this;}
    Publicacao& setarAno(int n){ano = n; return *this;}
    Publicacao& setarTitulo(string s){titulo = s; return *this;}
    Publicacao& setarEditora(string s){editora = s; return *this;}
    virtual Publicacao&  mostrar();
    virtual Publicacao& operator=(const Publicacao&);
    virtual bool operator==(const Publicacao&);
    friend ostream& operator<< (ostream&, const Publicacao&);
    friend istream& operator>> (istream&, Publicacao&);
};


#endif
