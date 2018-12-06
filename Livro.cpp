#include "Livro.hpp"
#include <sstream>


Livro::Livro(const Livro& L) : Publicacao(L) {
    autores = L.autores;
    qtdeExemplares = L.qtdeExemplares;
}
string Livro::obterAutores(){
    return autores;
}
int Livro::obterNumExemplares(){
    return qtdeExemplares;   
}
Livro& Livro::operator=(Livro& L){
    this->Publicacao::operator=(L);
    autores = L.autores;
    qtdeExemplares = L.qtdeExemplares;
    return *this;
}
bool Livro::operator==(Livro& L){
    if (autores != L.autores){return false;}
    if (qtdeExemplares != L.qtdeExemplares){return false;}
    return this->Publicacao::operator==(L);
}
ostream& operator<< (ostream& os, Livro& L){
    os<<"Titulo: "      <<L.obterTitulo()<<endl;
    os<<"Autores: "     <<L.obterAutores()<<endl;
    os<<"Ano: "         <<L.obterAutores()<<endl;
    os<<"Editora: "     <<L.obterEditora()<<endl;
    os<<"Exemplares: "  <<L.obterNumExemplares()<<endl;
    os<<"Código: "      <<L.obterCodigo()<<endl;
    return os;
}
istream& operator>> (istream& is , Livro& L){
    string aux, useless;
    // Read atribute titulo
    getline(is,aux);
    stringstream ssin(aux);
    ssin>>useless;
    aux = ssin.str();
    L.setarTitulo(aux);
    // Read atribute autores
    getline(is,aux);
    stringstream ssin(aux);
    ssin>>useless;
    aux = ssin.str();
    L.setarAutores(aux);
    // Read atribute ano
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    int ano = stoi(aux);
    L.setarAno(ano);
    // Read atribute Editora
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    L.setarEditora(aux);
    // Read Atribute exemplares
    getline(is,aux);
    stringstream ssin(aux);
    ssin>>useless;
    aux = ssin.str();
    int exemp = stoi(aux);
    L.setarExemplares(exemp);
    // Read atribute codigo
    getline(is,aux);
    ssin = stringstream(aux);
    ssin>>useless;
    aux = ssin.str();
    int cod = stoi(aux);
    L.setarCodigo(cod);
    return is;
} 