#ifndef _EMPRESTIMO_H__
#define _EMPRESTIMO_H__

#include <vector>
#include <string>
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
    static int proximoNumero; // o numero do proximo emprestimo
    int findPos(Livro& L);
    bool has(Livro& L);
  public:
    //constroi um emprestimo com os seguintes valores: numero (próximo
    //número sequencial), dataEmprestimo (data corrente do sistema), dataPrevDevolucao e usuário (passados
    //como argumentos);
    Emprestimo(const std::string& dataPrevDev = std::string("01/01/1900"), const Usuario& u = Usuario()) :
      numero(proximoNumero++), dataEmprestimo(Date()), dataPrevDevolucao(Date(dataPrevDev)), usuario(u) {}
    static void setaProximoNumero(const int& i) { proximoNumero = i;}
    Usuario& obterUsuario(){return usuario;}
    Emprestimo& mostrar();
    int  obterNumero() const {return numero;}
    int  obterNumItens() const {return itens.size();}
    void AdicionarLivro(Livro& L); // adiciona um livro ao Emprestimo
    void RemoverLivro(Livro& L); // remove um livro do Emprestimo
    void DevolverLivro(Livro& L); // devolve um livro do Emprestimo
    int  DevolverTudo(); // devolve todos os livros do Emprestimo
    bool contemLivro(const Livro* L);
    int  findPos(Livro&);
    bool operator==(Emprestimo& E){return numero == E.numero;}
    friend std::ostream& operator<< (std::ostream& out, const Emprestimo& E);
    int  findPos(ItemEmprestimo&);
    friend std::istream& operator>> (std::istream& in, Emprestimo& E);
    ~Emprestimo(){} // destroi o Emprestimo
};

#endif
