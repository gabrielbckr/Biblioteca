#include "Emprestimo.hpp"

int Emprestimo::proximoNumero = 1;

int Emprestimo::findPos(Livro& L){
    for (unsigned int ii =0; ii<itens.size(); ii++){
        if ( itens[ii]==L ){
            return ii;
        }
    }
    return -1;
}
bool Emprestimo::has(Livro& L){
    for (unsigned int ii =0; ii<itens.size(); ii++){
        if ( itens[ii]==L ){
            return true;
        }
    }
    return false;
}
// deve existir um método para adicionar um item (livro) ao empréstimo. Argumento: o livro. A quantidade
// de exemplares do livro deve ser decrementada de uma unidade (verificar se a quantidade é suficiente);
void Emprestimo::AdicionarLivro(Livro& L) {
    if (has(L)) {
        throw "este livro ja foi adicionado";
        return;
    }
    if (L.obterNumExemplares() > 0) {
        itens.push_back(ItemEmprestimo(L));
        L--;
    } else throw "nao ha exemplares disponiveis";
}
// deve existir um método para excluir um item (livro) do empréstimo. Argumento: o livro a ser excluído. A
// quantidade de exemplares do livro deve ser incrementada de uma unidade;
void Emprestimo::RemoverLivro(Livro& L) {
    int aux = findPos(L);
    if (aux != -1) {
        itens.erase(itens.begin() + aux);
        L++;
    } else throw "o livro nao consta na lista de itens";
}
// deve existir um método para devolver um item (livro) do empréstimo. Argumento: o livro a ser
// devolvido. A quantidade de exemplares do livro deve ser incrementada de uma unidade. A data de
// devolução do item deve ser atualizada pela data do sistema;
void Emprestimo::DevolverLivro(Livro& L) {
    int aux = findPos(L);
    if (aux == -1)
        throw "o livro nao consta na lista de itens";
    else if (itens[aux].pegarDataDev() == std::string("01/01/1900")) {
        itens[aux].atualizarDataDev();
        L++;
    } else throw "o livro ja foi devolvido";
}
// deve existir um método para devolver todos os livros do empréstimo. A quantidade de exemplares de
// todos os itens (livros) do empréstimo deve ser incrementada de uma unidade. A data de devolução de
// todos os itens deve ser atualizada pela data do sistema;
int Emprestimo::DevolverTudo() {
    int devolvidos = 0;
    for (unsigned int i = 0; i < itens.size(); i++) {
        if (itens[i].pegarDataDev() != std::string("01/01/1900"))
            continue;
        else {
            itens[i].atualizarDataDev();
            itens[i]++;
            devolvidos++;
        }
    }
    return devolvidos;
}
bool Emprestimo::contemLivro(const Livro* L){
    return (itens.findPos(*L)!=-1);
}
std::ostream& operator<< (std::ostream& out, const Emprestimo& E) {
    out << E.numero << std::endl;
    out << E.dataEmprestimo << std::endl;
    out << E.dataPrevDevolucao << std::endl;
    out << E.usuario << std::endl;
    out << E.itens << std::endl;
    return out;
}
std::istream& operator>> (std::istream& in, Emprestimo& E) {
    string line;
    std::getline(in, line);
    E.numero = std::stoi(line);
    in >> E.dataEmprestimo;
    in >> E.dataPrevDevolucao;
    in >> E.usuario;
    in >> E.itens;
    return in;
}
Emprestimo& Emprestimo::mostrar(){
    cout << "Numero: " <<numero << std::endl;
    cout << "DataEmprestimo: " <<dataEmprestimo << std::endl;
    cout << "Devolução: " <<dataPrevDevolucao << std::endl;
    cout << "Usuario: " <<usuario.mostrar()<<endl;  // Talvez tenha q tirar esse endl
    cout << "Itens: " <<itens << std::endl;   // Talvez tenha que fazer itens mostrar
    return *this;
}
int  Emprestimo::findPos(Livro& L){
    for (int ii =0; ii<itens.size(); ii++){
        if ( itens[ii]==L ){
            return ii;
        }
    }
    return -1;
}
int  Emprestimo::findPos(ItemEmprestimo& I){
    for (int ii =0; ii<itens.size(); ii++){
        if ( itens[ii]==I ){
            return ii;
        }
    }
    return -1;
}