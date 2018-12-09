#include "Interface.hpp"

#define bib (*biblioteca) 
using namespace std;

void Interface::cadastrarUsuario(){
    string nome, cpf, endereco, fone;
    cout<<"Inserir Usuario (Nome, CPF, Endereco, Telefone):"<<endl;
    cout<<"Nome: "; getline(cin,nome); 
    cout<<"CPF: "; getline(cin,cpf);
    cout<<"Endereco: "; getline(cin,endereco);
    cout<<"Telefone: "; getline(cin,fone);
    Usuario usr(nome, cpf, endereco, fone);
    bib.adicionarUsuario(usr);
}
void Interface::cadastrarLivro(){
    string tit, ed, autores;
    int ano, cod;
    cout<<"Inserir Livro (Titulo, Autores, Edicao, Ano, Codigo)"<<endl;
    cout<<"Titulo:"; getline(cin,tit); 
    cout<<"Autores: "; getline(cin,autores);
    cout<<"Edicao: "; cin>>ed;
    cout<<"Ano: "; cin>>ano;
    cout<<"Codigo: "; cin>>cod;
    Livro L(tit, ed, ano, cod, autores);
    //bib.adicionarLivro(L);
}
void Interface::cadastrarPeriodico(){
    string tit, ed, mes;
    int ano, cod, numEd;
    cout<<"Inserir Livro (Titulo, Edicao, Ano, Codigo, Mes, Numero da Edicao)"<<endl;
    cout<<"Titulo:"; getline(cin,tit); 
    cout<<"Edicao: "; cin>>ed;
    cout<<"Ano: "; cin>>ano;
    cout<<"Codigo: "; cin>>cod;
    cout<<"Mes: "; cin>>mes;
    cout<<"Numero: "; cin>>numEd;
    Periodico P(tit, ed, ano, cod, mes, numEd);
    //bib.adicionarPeriodico(P);
}
void Interface::cadastrarEmprestimo(){

}
void Interface::inserirItem(){
    
}
void Interface::excluirUsuario(){
    
}
void Interface::excluirLivro(){
    
}
void Interface::excluirPeriodico(){
    
}
void Interface::excluirEmprestimo(){
    
}
void Interface::excluirItem(){
    
}
void Interface::devolverTodoEmprestimo(){
    
}
void Interface::devolverLivro(){
    
}
void Interface::pesquisarPublicacao(){

}
void Interface::pesquisarLivroAutor(){
    
}
void Interface::listarPublicacoes(){
    cout<<"LIVROS:"<<endl;
    cout<<bib.obterLivros();
    cout<<"PERIODICOS:"<<endl;
    cout<<bib.obterPeriodicos();
}
void Interface::listarEmprestimos(){

}
void Interface::salvarArquivo(){
    cout<<"Digite o nome do arquivo onde deseja salvar: "<<endl;
    string nome;
    cin>>nome;
    if (nome.find(string(".txt")) == string::npos){
       nome+=string(".txt"); 
    }
    cout<<"Biblioteca salva em: "<<nome<<endl;
    bib.arquivarConteudo(nome);
}
void Interface::exibirMenu(){
}