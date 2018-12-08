#include "Emprestimo.hpp"

int Emprestimo::proximoNumero = 1;

// deve existir um método para adicionar um item (livro) ao empréstimo. Argumento: o livro. A quantidade
// de exemplares do livro deve ser decrementada de uma unidade (verificar se a quantidade é suficiente);
void Emprestimo::AdicionarLivro(Livro& L) {
    if (itens.has(ItemEmprestimo(L))) {
        throw "este livro ja foi adicionado";
        return;
    }
    if (L.obterNumExemplares > 0) {
        itens.push_back(ItemEmprestimo(L));
        L--;
    } else throw "nao ha exemplares disponiveis";
}
void Emprestimo::RemoverLivro(Livro& L) {
    int aux = itens.findPos(ItemEmprestimo(L));
    if (aux != -1) {
        itens.erase(itens.begin() + aux);
        L++;
    } else throw "o livro nao consta na lista de itens";
}
void DevolverLivro(Livro& L){}
void DevolverTudo(){}
