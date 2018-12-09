#include "Biblioteca.hpp"
#include <fstream>
using namespace std;

Biblioteca& Biblioteca::arquivarConteudo(string& nome){
    fstream arquivo;
    arquivo.open(nome, fstream::out | fstream::trunc);
    arquivo<<usuarios;
    arquivo<<livros;
    arquivo<<periodicos;
    //arquivo<<emprestimos;
    return *this;
}
Biblioteca& Biblioteca::lerArquivo(string& nome){
    fstream arquivo;
    arquivo.open(nome, fstream::in | fstream::app);
    arquivo>>usuarios;
    arquivo>>livros;
    arquivo>>periodicos;
    //arquivo>>emprestimos;
    return *this;
}
myVector<Livro>& Biblioteca::buscaLivroAutor(const string& s){
    myVector<Livro> vec;
    string autores;
    for (int ii = 0 ; ii < livros.size(); ii++){
        autores = livros[ii].obterAutores();
        if (!(autores.find(s) == string::npos)){
            vec.push_back(vec[ii]);
        }
    }
    return vec;
}
myVector<Publicacao>& Biblioteca::buscaPublicacao(const string& s){
    myVector<Publicacao> vec;
    string titulo;
    for (int ii = 0 ; ii < livros.size(); ii++){
        titulo = livros[ii].obterTitulo();
        if (!(titulo.find(s) == string::npos)){
            vec.push_back(livros[ii]);
        }
    }
    for (int ii = 0 ; ii < periodicos.size(); ii++){
        titulo = periodicos[ii].obterTitulo();
        if (!(titulo.find(s) == string::npos)){
            vec.push_back(periodicos[ii]);
        }
    }
    return vec;
}
myVector<Publicacao>& Biblioteca::obterPublicacoes(){
    myVector<Publicacao> vecp;
    for (int ii = 0 ; ii < livros.size(); ii++){
            vecp.push_back(livros[ii]);
    }
    for (int ii = 0 ; ii < periodicos.size(); ii++){
            vecp.push_back(periodicos[ii]);
    }
    return vecp;
}
myVector<Periodico>& Biblioteca::obterPeriodicos(){
    myVector<Periodico> vecp;
    for (int ii = 0 ; ii < periodicos.size(); ii++){
            vecp.push_back(periodicos[ii]);
    }
    return vecp;
} 
Biblioteca& Biblioteca::adicionarUsuario(Usuario& U){
    int pos = usuarios.findPos(U);
    if (pos==-1){
        usuarios.push_back(U);
    }
    return *this;
}
/*Biblioteca& Biblioteca::adicionarPublicacao(Publicacao& P){
    int pos = periodicos.findPos(L);
    if (pos!=-1){
        livros[pos]++;
    }
    return *this;
}*/
Biblioteca& Biblioteca::adicionarLivro(Livro& L){
    int pos = livros.findPos(L);
    if (pos!=-1){
        livros[pos]++;
    }
    else{
        L.setarExemplares(1);
        livros.push_back(L);
    }
    return *this;
}
Biblioteca& Biblioteca::adicionarPeriodico(Periodico& P){
    int pos = periodicos.findPos(P);
    if (pos==-1){
        periodicos.push_back(P);
    }
    return *this;
}
Biblioteca& Biblioteca::adicionarEmprestimo(Emprestimo&){}
Biblioteca& Biblioteca::excluirUsuario(Usuario){} // não pode ser excluído se existir algum empréstimo para ele
Biblioteca& Biblioteca::excluirEmprestimo(const Emprestimo){}
Biblioteca& Biblioteca::exluirItemEmprestimo( Emprestimo, ItemEmprestimo){}
myVector<Usuario>& Biblioteca::obterUsuarios(){
    myVector<Usuario> vecp;
    for (int ii = 0 ; ii < usuarios.size(); ii++){
            vecp.push_back(usuarios[ii]);
    }
    return vecp;
}
myVector<Emprestimo>& Biblioteca::obterEmprestimos(){}
Biblioteca& Biblioteca::inserirItemEmprestimo(Emprestimo, ItemEmprestimo){}
Biblioteca& Biblioteca::excluirPublicacao(Publicacao){}  // Se a publicação for um livro, este não pode ser excluído se existir algum empréstimo para ele;
Biblioteca& Biblioteca::devolverItem(Emprestimo, Livro){}
Biblioteca& Biblioteca::devolverTodosItens(Emprestimo){}
myVector<Livro>& Biblioteca::obterLivros(){
    return livros;
}