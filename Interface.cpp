#include "Interface.hpp"

#define bib (*biblioteca) 
using namespace std;

#ifdef __linux__
#define __INIT__ system("stty raw")
#define __GET_CHAR__ getchar()
#define __CLEAR__ system("clear")
#define __END__  system("stty cooked")
#elif _WIN32 
#include <conio.h>
#include <windows.h>
#define __INIT__ system("cls")
#define __GET_CHAR__ _getch()
#define __CLEAR__ system("cls")
#define __END__  system("cls")
#else
#define __INIT__ 
#define __GET_CHAR__ getchar()
#define __CLEAR__
#define __END__  
#endif

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
    char op;
    Usuario u;
    string s;
    int i;
    cout<<"Insira os dados do usuario a ser excluido"<<endl;
    cout<<"Digite o nome: "<<endl; getline(cin,s);
    u.setarNome(s);
    cout<<"Digite o CPF: "<<endl; getline(cin,s);
    u.setarCpf(s);
    op = __GET_CHAR__;
    myVector<Usuario>& usr = bib.obterUsuarios();
    int pos = usr.findPos(u);
    if (pos == -1){
        cout<<"Usuario nao encontrado. Tente novamente."<<endl;
        return ;
    }else{
        myVector<Emprestimo>& empr = bib.obterEmprestimos();
        for(int ii = 0; ii<empr.size(); ii++){
            if (empr[ii].obterUsuario() == u){
                cout<<"O Usuario possui emprestimo e, por tanto, nao pode ser excluido."<<endl;
                return;
            }
        }
        bib.excluirUsuario(usr[pos]);
    }
    
}
void Interface::excluirLivro(){
    
}
void Interface::excluirPeriodico(){
    char op;
    Usuario u;
    string s;
    int i;
    cout<<"Insira os dados do periodico a ser excluido"<<endl;
    cout<<"Digite o nome: "<<endl; getline(cin,s);
    u.setarNome(s);
    cout<<"Digite o CPF: "<<endl; getline(cin,s);
    u.setarCpf(s);
    op = __GET_CHAR__;
    myVector<Usuario> usr = bib.obterUsuarios();
    int pos = usr.findPos(u);
    if (pos == -1){
        cout<<"Usuario nao encontrado. tente novamente."<<endl;
        return ;
    }else{

    }
}
void Interface::excluirEmprestimo(){
    
}
void Interface::excluirItem(){
    
}
void Interface::devolverTodoEmprestimo(){
    
}
void Interface::devolverLivro(){
    string usuario,  titulo;
    cout<<"Digite o nome do usuario que vai devolver o Livro:"<<endl;
    getline(cin,usuario);
    cout<<"Digite o Titulo do Livro a ser devolvido";
    cin>>titulo;
    myVector<Emprestimo> empr = bib.obterEmprestimos();
    myVector<Publicacao*> ls = bib.buscaPublicacao(titulo);
    if (ls.size()>1){
        cout<<"TItulo do Livro muito inespecifico. Tente novamente"<<endl;
        return;
    }
    else if(ls.size()<1){
        cout<<"TItulo nao foi encontrado"<<endl;
        return;
    }
    for(int ii = 0; ii<empr.size(); ii++){
        if(empr[ii].obterUsuario().pegarNome() == usuario  ){
            Livro* OLivro = dynamic_cast<Livro*> (ls[0]);
            empr[ii].DevolverLivro(*OLivro);
            cout<<"Livro devolvido com sucesso"<<endl;
            return;
        }
        else{
            cout<<"Livro nao foi devolvido"<<endl;
        }
    }

}
void Interface::pesquisarPublicacao(){
    cout<<"Digite a palavra a ser pesquisada:"<<endl;
    string pesquise;
    cin>>pesquise;
    myVector<Livro> livros = bib.buscaLivroAutor(pesquise);
    for (int ii =0; ii<livros.size(); ii++){
        livros[ii].mostrar();
    }
    myVector<Publicacao*> pubs = bib.buscaPublicacao(pesquise);
    for (int ii =0; ii<pubs.size(); ii++){
        pubs[ii]->mostrar();
    }
}
void Interface::pesquisarLivroAutor(){
    cout<<"Digite o nome da/do autora/autor:"<<endl;
    string pesquise;
    cin>>pesquise;
    myVector<Livro> livros = bib.buscaLivroAutor(pesquise);
    for (int ii =0; ii<livros.size(); ii++){
        livros[ii].mostrar();
    }
}
void Interface::listarPublicacoes(){
    cout<<"LISTA DE PUBLICACOES:"<<endl;
    cout<<"LIVROS:"<<endl;
    myVector<Livro>& livros = bib.obterLivros();
    for (int ii =0; ii<livros.size(); ii++){
        livros[ii].mostrar();
    }
    cout<<"PERIODICOS:"<<endl;
    myVector<Periodico>& periodicos = bib.obterPeriodicos();
    for (int ii =0; ii<periodicos.size(); ii++){
        periodicos[ii].mostrar();
    }
}
void Interface::listarEmprestimos(){
    cout<<"LISTA DE EMPRESTIMOS"<<endl;
    myVector<Emprestimo>& empr = bib.obterEmprestimos();
    for (int ii =0; ii<empr.size(); ii++){
        empr[ii].mostrar();
    }
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
    /*__INIT__;
    while(true){
        cout<<"1 - Cadastrar | ESC - Sair"<<endl;
        char op = __GET_CHAR__;
        switch (op){
            case '1':
                cout<<" A - Cadastrar Livro | B"<<endl;  
        
        }
    }
    __END__;
    */
}
Interface::Interface(){
}
Interface::Interface(Biblioteca* b):biblioteca(b){
    __INIT__;
}
Interface::Interface(Biblioteca& b):biblioteca(&b){
    __INIT__;
}
Interface::~Interface(){
    __END__;
}