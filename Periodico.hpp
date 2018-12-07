#ifndef _PERIODICO_H__
#define _PERIODICO_H__

#include <string>
#include "Publicacao.hpp"

using namespace std;

class Periodico: public Publicacao{
    string mes;
    int numEdicao;
public:
    Periodico(const string& t  = string("def"), const string& ed = string("def"),
            const int& a = 0, const int& cod = 0, const string& Mes = string("def"),const int& numEd = 0):
            Publicacao(t,ed,a,cod), mes(Mes), numEdicao(numEd){}
    Periodico(const Periodico&);
    ~Periodico(){}
    string obterMes(){return mes;}
    int obterEdicao(){return numEdicao;}
    Periodico& setarEdicao(int n){numEdicao = n; return *this;}
    Periodico& setarMes(string n){mes = n; return *this;}
    Periodico& operator=(const Periodico&);
    Periodico& mostrar();
    bool operator==(const Periodico&);
    friend ostream& operator<< (ostream&, Periodico&);
    friend istream& operator>> (istream&, Periodico&);
};

#endif
