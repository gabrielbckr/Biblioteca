#include "Periodico.hpp"
#include <sstream>


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
Periodico& Periodico::mostrar(){
    cout<<"Titulo: " <<obterTitulo()<<endl;
    cout<<"Ano: "    <<obterAno()<<endl;
    cout<<"Mes: "    <<mes<<endl;
    cout<<"Edicao: " <<numEdicao<<endl;
    cout<<"Editora: "<<obterEditora()<<endl;
    cout<<"Código: " <<obterCodigo()<<endl;
    return *this;
}
ostream& operator<< (ostream& os, Periodico& P){
    os<<P.obterTitulo()<<endl;
    os<<P.obterAno()<<endl;
    os<<P.mes<<endl;
    os<<P.numEdicao<<endl;
    os<<P.obterEditora()<<endl;
    os<<P.obterCodigo()<<endl;
    return os;
}
istream& operator>> (istream& is , Periodico& P){
    string aux;
    getline(is,aux);
    P.setarTitulo(aux);
    getline(is,aux);
    P.setarAno(stoi(aux));
    getline(is,aux);
    P.mes = aux;
    getline(is,aux);
    P.numEdicao = stoi(aux);
    getline(is,aux);
    P.setarEditora(aux);
    getline(is,aux);
    P.setarCodigo(stoi(aux));
    return is;
} 