#ifndef _UINTERFACE_H__
#define _UINTERFACE_H__

#include <iostream>
#include <string>
#include "Biblioteca.hpp"

using namespace std;

class Interface {
    // TODO
public:
    Interface();
    void exibirMenu() const;
    void cadastrarUsuario(const Usuario) const;
    void cadastrarLivro(const Livro) const;
    void cadastrarPeriodico(const Periodico) const;
    void cadastrarEmprestimo(const Emprestimo) const;
    void inserirItem(const ItemEmprestimo, Emprestimo&)const;
    void excluirUsuario(Usuario&) const;
    void excluirLivro(Livro&) const;
    void excluirPeriodico(Periodico&) const;
    void excluirEmprestimo(Emprestimo&) const;
    void excluirItem(const ItemEmprestimo, Emprestimo&) const;
    void devolverTodoEmprestimo(Emprestimo&);
    void devolverLivro(Emprestimo&, Livro);
    void pesquisarPublicacao(string);
    void pesquisarLivroAutor(string);
    void listarPublicacoes();
    void listarEmprestimos();
    ~Interface();
};

#endif
