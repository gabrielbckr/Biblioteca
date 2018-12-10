#include "Interface.hpp"
#include "Biblioteca.hpp"

int main(int argc, char** argv){
    Biblioteca bib;
    if (argc>0){
        string nome = argv[0];
        bib.lerArquivo(nome);
    }
    Interface iter = Interface(bib);
    iter.exibirMenu();
}