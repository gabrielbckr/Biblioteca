#include "ItemEmprestimo.hpp"

void ItemEmprestimo::atualizarDataDev(const string& Data) {
    if (Data != "") dataDevolucao.setarData(Data);
    else dataDevolucao.Hoje();
}
const Date ItemEmprestimo::pegarDataDev() const {
    return dataDevolucao;
}
bool ItemEmprestimo::operator== (const ItemEmprestimo& IE) {
    return (livro == IE.livro);
}
bool ItemEmprestimo::isEqualTo (const ItemEmprestimo& IE) {
    if (dataDevolucao.pegarData() != IE.dataDevolucao.pegarData())
        return false;
    if (livro == IE.livro)
        return true;
    return false;
}
ItemEmprestimo& ItemEmprestimo::operator= (const ItemEmprestimo& IE) {
    dataDevolucao = IE.pegarDataDev();
    livro = IE.livro;
    return *this;
}
ItemEmprestimo::~ItemEmprestimo(){}
