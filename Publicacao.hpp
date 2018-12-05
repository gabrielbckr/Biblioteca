#ifndef _PUBLIC_LIBRY_
#define _PUBLIC_LIBRY_

#include <string>
using namespace std;

class Publicacao{
    int codPublicacao, ano;
    string titulo, editora;
public:
    Publicacao(string t, string ed, int a, int cod):
                titulo(t), editora(ed),ano(a), codPublicacao(cod){};
    virtual ~Publicacao();
    int obterAno();
    int obterCodigo();
    string obterTitulo();
    string obtereEditora();
    virtual bool operator==(Publicacao& p);
};


#endif
