#include "Periodico.hpp"


Periodico::Periodico(const Periodico& P) : Publicacao(P){
    mes = P.mes;
    numEdicao = P.numEdicao;
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
ostream& operator<< (ostream& os, Periodico& P){
    os<<"Titulo: " <<P.obterTitulo()<<endl;
    os<<"Ano: "    <<P.obterAno()<<endl;
    os<<"Mes: "    <<P.mes<<endl;
    os<<"Edicao: " <<P.numEdicao<<endl;
    os<<"Editora: "<<P.obterEditora()<<endl;
    os<<"Código: " <<P.obterCodigo()<<endl;
    return os;
}