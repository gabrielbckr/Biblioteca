#include "Interface.hpp"
#include "Biblioteca.hpp"

int main(int argc, char** argv){
    Biblioteca bib;
    if (argc>1){
        string nome = string(argv[1]);
        bib.lerArquivo(nome);
    }
    Interface iter = Interface(bib);
    iter.exibirMenu();
}