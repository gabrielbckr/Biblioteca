#ifndef _EMPRESTIMO_H__
#define _EMPRESTIMO_H__

#include <vector>
#include "myVector.hpp"
#include "Date.hpp"
#include "Usuario.hpp"
#include "ItemEmprestimo.hpp"
#include "Livro.hpp"

class Emprestimo {
    int numero; // numero do emprestimo
    Date dataEmprestimo, dataPrevDevolucao; // data do emprestimo, data prevista para devolucao
    Usuario usuario; // usuario que realizou o emprestimo
    myVector<ItemEmprestimo> itens; // itens emprestados
  public:
    static int proximoNumero; // o numero do proximo emprestimo
    //constroi um emprestimo com os seguintes valores: numero (próximo
    //número sequencial), dataEmprestimo (data corrente do sistema), dataPrevDevolucao e usuário (passados
    //como argumentos);
    Emprestimo(const string& dataPrevDev, const Usuario& u) :
      numero(proximoNumero++), dataEmprestimo(Date()), dataPrevDevolucao(Date(dataPrevDev)), usuario(u) {}
    void AdicionarLivro(Livro& L); // adiciona um livro ao Emprestimo
    void RemoverLivro(Livro& L); // remove um livro do Emprestimo
    void DevolverLivro(Livro& L); // devolve um livro do Emprestimo
    void DevolverTudo(); // devolve todos os livros do Emprestimo
    ~Emprestimo(){} // destroi o Emprestimo
};

#endif
