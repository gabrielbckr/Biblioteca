#include "Interface.hpp"
#include "Biblioteca.hpp"

int main(){
    Biblioteca bib;
    Interface iter = Interface(bib);
    iter.exibirMenu();
}