#ifndef _PERIODICO_H__
#define _PERIODICO_H__

#include <string>
#include "Publicacao.hpp"

using namespace std;

class Periodico: public Publicacao{
    string mes;
    int numEdicao;
public:
    Periodico(string Mes, int numEd):mes(Mes), numEdicao(numEd){}
    ~Periodico();
};

#endif
