#include "Periodico.hpp"
#include <sstream>


Periodico::Periodico(const Periodico& P) : Publicacao(P){
    mes = P.mes;
    numEdicao = P.numEdicao;
}
Periodico& Periodico::operator=(Periodico& P){
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
istream& operator>> (istream& is , Periodico& P){
    string aux, useless;
    // Read atribute titulo
    getline(is,aux);
    stringstream ssin(aux);
    ssin>>useless;
    aux = ssin.str();
    P.setarTitulo(aux);
    // Read atribute ano
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    int ano = stoi(aux);
    P.setarAno(ano);
    // Read atribute mes
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    P.setarMes(aux);
    // Read edicao
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    int ed = stoi(aux);
    P.setarEdicao(ed);
    // Read atribute Editora
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    P.setarEditora(aux);
    // Read atribute codigo
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    int cod = stoi(aux);
    P.setarCodigo(cod);
    return is;
} 