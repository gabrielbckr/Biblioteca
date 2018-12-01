#include "ItemEmprestimo.hpp"

void ItemEmprestimo::atualizarDataDev(const string& Data) {
    if (Data != "") dataDevolucao.setarData(Data);
    else dataDevolucao.Hoje();
}
const Date ItemEmprestimo::pegarDataDev() const {
    return dataDevolucao;
}
ItemEmprestimo::~ItemEmprestimo(){}