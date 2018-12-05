#include "Periodico.hpp"


Periodico::Periodico(const Periodico& P) : Publicacao(P){
    mes = P.mes;
    numEdicao = P.numEdicao;
}
string Periodico::obterMes(){
    return mes;
}
int Periodico::obterEdicao(){
    return numEdicao;
}
Periodico& Periodico::operator=(const Periodico& P){
    this->Publicacao::operator=(P);
    mes = P.mes;
    numEdicao = P.numEdicao;
    return *this;
}
bool Periodico::operator==(const Periodico& P){
    if (numEdicao != P.numEdicao){return false;}
    if (mes != P.mes){return false;}
    return this->Publicacao::operator==(P);
}