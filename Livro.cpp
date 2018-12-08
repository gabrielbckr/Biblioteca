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
Livro& Livro::operator=(const Livro& L){
    this->Publicacao::operator=(L);
    autores = L.autores;
    qtdeExemplares = L.qtdeExemplares;
    return *this;
}
bool Livro::operator==(const Livro& L) {
    if (autores != L.autores){return false;}
    if (qtdeExemplares != L.qtdeExemplares){return false;}
    return this->Publicacao::operator==(L);
}
Livro& Livro::mostrar(){
    cout<<"Titulo: "      <<obterTitulo()<<endl;
    cout<<"Autores: "     <<obterAutores()<<endl;
    cout<<"Ano: "         <<obterAno()<<endl;
    cout<<"Editora: "     <<obterEditora()<<endl;
    cout<<"Exemplares: "  <<obterNumExemplares()<<endl;
    cout<<"Código: "      <<obterCodigo()<<endl;
    return *this;
}
ostream& operator<< (ostream& os, Livro& L){
    os<<L.obterTitulo()<<endl;
    os<<L.obterAutores()<<endl;
    os<<L.obterAno()<<endl;
    os<<L.obterEditora()<<endl;
    os<<L.obterNumExemplares()<<endl;
    os<<L.obterCodigo()<<endl;
    return os;
}
istream& operator>> (istream& is , Livro& L){
    string aux;
    getline(is,aux);
    L.setarTitulo(aux);
    getline(is,aux);
    L.setarAutores(aux);
    getline(is,aux);
    L.setarAno(stoi(aux));
    getline(is,aux);
    L.setarEditora(aux);
    getline(is,aux);
    L.qtdeExemplares = stoi(aux);
    getline(is,aux);
    L.setarCodigo(stoi(aux));
    return is;
}
