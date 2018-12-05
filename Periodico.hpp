#ifndef _PERIODICO_H__
#define _PERIODICO_H__

#include <string>
#include "Publicacao.hpp"

using namespace std;

class Periodico: public Publicacao{
    string mes;
    int numEdicao;
public:
    Periodico(string t, string ed, int a, int cod, string Mes, int numEd):
            Publicacao(t,ed,a,cod), mes(Mes), numEdicao(numEd){}
    Periodico(const Periodico&);
    ~Periodico(){}
    string obterMes();
    int obterEdicao();
    Periodico& operator=(const Periodico&);
    bool operator==(const Periodico&);
};

#endif
