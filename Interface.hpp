#ifndef _UINTERFACE_H__
#define _UINTERFACE_H__

#include <iostream>
#include <string>
#include "Biblioteca.hpp"

using namespace std;

class Interface {
    Biblioteca* biblioteca;
public:
    Interface();
    Interface(Biblioteca* b):biblioteca(b){};
    Interface(Biblioteca& b):biblioteca(&b){};
    void exibirMenu() ;
    void cadastrarUsuario() ;
    void cadastrarLivro();
    void cadastrarPeriodico();
    void cadastrarEmprestimo();
    void inserirItem() ;
    void excluirUsuario();
    void excluirLivro() ;
    void excluirPeriodico() ;
    void excluirEmprestimo();
    void excluirItem();
    void devolverTodoEmprestimo();
    void devolverLivro();
    void pesquisarPublicacao();
    void pesquisarLivroAutor();
    void listarPublicacoes();
    void listarEmprestimos();
    ~Interface();
};

#endif
