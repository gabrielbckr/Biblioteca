#ifndef _ITEM_EMPRESTIMO_H__
#define _ITEM_EMPRESTIMO_H__

#include "Date.hpp"
#include "Livro.hpp"

class ItemEmprestimo {
    Date dataDevolucao; // data da devolucao
    Livro livro; // livro emprestado
  public:
    ItemEmprestimo(Livro); // constroi um ItemEmprestimo
    ~ItemEmprestimo(); // destroi o ItemEmprestimo
};

#endif
