#ifndef _EMPRESTIMO_H__
#define _EMPRESTIMO_H__

#include <vector>
#include "Date.hpp"
#include "Usuario.hpp"
#include "ItemEmprestimo.hpp"
#include "Livro.hpp"

using namespace std;

class Emprestimo {
    int numero; // numero do emprestimo
    Date dataEmprestimo, dataPrevDevolucao; // data do emprestimo, data prevista para devolucao
    Usuario usuario; // usuario que realizou o emprestimo
    vector<ItemEmprestimo> itens; // itens emprestados
  public:
    static int proximoNumero; // o numero do proximo emprestimo
    Emprestimo(int, Date, Date, Usuario); // constroi um Emprestimo
    void AdicionarLivro(Livro); // adiciona um livro ao Emprestimo
    void RemoverLivro(Livro); // remove um livro do Emprestimo
    void DevolverLivro(Livro); // devolve um livro do Emprestimo
    void DevolverTudo(); // devolve todos os livros do Emprestimo
    ~Emprestimo(); // destroi o Emprestimo
};

#endif
