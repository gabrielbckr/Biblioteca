#include "Publicacao.hpp"
#include <sstream>

Publicacao::Publicacao(const Publicacao& p){
    ano           = p.ano;
    codPublicacao = p.codPublicacao;
    editora       = p.editora;
    titulo        = p.titulo;
}
Publicacao& Publicacao::operator=(const Publicacao& p){
    ano           = p.ano;
    codPublicacao = p.codPublicacao;
    editora       = p.editora;
    titulo        = p.titulo;
    return *this;
}
bool Publicacao::operator==(const Publicacao& p){
    if (ano!=p.ano){return false;}
    if (codPublicacao!=p.codPublicacao){return false;}
    if (editora!=p.editora){return false;}
    if (titulo!=p.titulo){return false;}
    return true;
}
Publicacao& Publicacao::mostrar(){
    cout<<"Titulo: " <<obterTitulo()<<endl;
    cout<<"Ano: "    <<obterAno()<<endl;
    cout<<"Editora: "<<obterEditora()<<endl;
    cout<<"Código: " <<obterCodigo()<<endl;
    return *this;
}
ostream& operator<< (ostream& os, const Publicacao& P){
    os<<P.obterTitulo()<<endl;
    os<<P.obterAno()<<endl;
    os<<P.obterEditora()<<endl;
    os<<P.obterCodigo()<<endl;
    return os;
}
istream& operator>> (istream& is , Publicacao& P){
    string aux;
    getline(is, aux);
    P.setarTitulo(aux);
    getline(is, aux);
    P.setarAno(stoi(aux));
    getline(is, aux);
    P.setarEditora(aux);
    getline(is, aux);
    P.setarCodigo(stoi(aux));
    return is;
}
Publicacao::~Publicacao(){}
