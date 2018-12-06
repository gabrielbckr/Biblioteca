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
}
bool Publicacao::operator==(const Publicacao& p){
    if (ano!=p.ano){return false;}
    if (codPublicacao!=p.codPublicacao){return false;}
    if (editora!=p.editora){return false;}
    if (editora!=p.editora){return false;}
    if (titulo!=p.titulo){return false;}
    return true;
}
ostream& operator<< (ostream& os, Publicacao& P){
    os<<"Titulo: " <<P.obterTitulo()<<endl;
    os<<"Ano: "    <<P.obterAno()<<endl;
    os<<"Editora: "<<P.obterEditora()<<endl;
    os<<"Código: " <<P.obterCodigo()<<endl;
    return os;
}
istream& operator>> (istream& is , Publicacao& P){
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