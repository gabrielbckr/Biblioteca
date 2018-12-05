#include "Livro.hpp"


Livro::Livro(Livro& L) : Publicacao(L) {
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
    autores = L.autores;
    qtdeExemplares = L.qtdeExemplares;
}
bool Livro::operator==(Livro& L){
    if (autores != L.autores){return false;}
    if (qtdeExemplares != L.qtdeExemplares){return false;}
    return this->Publicacao::operator==(L);
}