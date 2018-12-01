#ifndef _ITEM_EMPRESTIMO_H__
#define _ITEM_EMPRESTIMO_H__

#include "Date.hpp"
#include "Livro.hpp"
#include <string>

class ItemEmprestimo {
    Date dataDevolucao; // data da devolucao
    Livro livro; // livro emprestado
  public:
    ItemEmprestimo(const Livro& L) : livro(L), dataDevolucao("01/01/1900") {}; // constroi um ItemEmprestimo
    void atualizarDataDev(const string& Data);
    const Date pegarDataDev() const;
    ~ItemEmprestimo(); // destroi o ItemEmprestimo
};

#endif
