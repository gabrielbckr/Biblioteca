#include "Publicacao.hpp"


Publicacao::Publicacao(const Publicacao& p){
    ano           = p.ano;
    codPublicacao = p.codPublicacao;
    editora       = p.editora;
    titulo        = p.titulo;
}
int Publicacao::obterAno(){
    return ano;
}
int Publicacao::obterCodigo(){
    return codPublicacao;
}
string Publicacao::obterTitulo(){
    return titulo;
}
string Publicacao::obtereEditora(){
    return editora;
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