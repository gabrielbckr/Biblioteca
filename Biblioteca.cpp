#include "Biblioteca.hpp"
#include <fstream>
using namespace std;
Biblioteca& Biblioteca::arquivarConteudo(string& nome){
    fstream arquivo;
    arquivo.open(nome, fstream::in | fstream::trunc);
    arquivo<<usuarios;
    arquivo<<livros;
    arquivo<<emprestimos;
    return *this;
}