#include "Interface.hpp"

#define bib (*biblioteca) 
using namespace std;

#ifdef __linux__
#define __INIT__ system("stty raw  opost") // modifica entrada do teclado para nao precisar de enter
#define __GET_CHAR__ getchar()
#define __CLEAR__ system("clear") // limpa display
#define __END__  system("stty cooked") // desfaz __INIT__
#elif _WIN32 
#include <conio.h>
#include <windows.h>
#define __INIT__ system("cls")  // __INIT__ nao é necessario se é windows
#define __GET_CHAR__ _getch() // pq conio ja tem a funçã oque faz isso tuso
#define __CLEAR__ system("cls") // limpa display
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
    Usuario u;
    string s;
    cout<<"Insira os dados do usuario a ser excluido"<<endl;
    cout<<"Digite o nome: "<<endl; getline(cin,s);
    u.setarNome(s);
    cout<<"Digite o CPF: "<<endl; getline(cin,s);
    u.setarCpf(s);
    try{
        bib.excluirUsuario(u);
    }catch(string s){
        cout<< s<<endl;
    };
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
    char op;
    __CLEAR__;
    imprimirPrimeiroMenu();
    do{
        __INIT__;
        op = __GET_CHAR__;
        __END__;
        cout<<endl;
        switch (op){
            case '1': // 
                __CLEAR__;
                imprimirPrimeiroMenu();
                cout<<"CADASTRAR: a - Usuario | "
                <<"b - Livro | "
                "c - Periodico | "
                "d - Emprestimo | "<<endl;
                break;  
            case '2': //      
                __CLEAR__;
                imprimirPrimeiroMenu();
                cout<<"EXLUIR: e - Usuario | "
                <<"f - Livro | "
                <<"g - Periodico | "
                <<"h - Emprestimo | "
                <<"i - Item | "<<endl;
                break;
            case '3': //   
                __CLEAR__;
                imprimirPrimeiroMenu();
                cout<<"PESQUISAR: j - Publicacao | "
                <<"k - Livro por nome |"<<endl;
                break;
            
            case '4': // Devolver   
                __CLEAR__;
                imprimirPrimeiroMenu();
                cout<<"DEVOLVER: l - Emprestimo Inteiro | "
                <<"m - Apenas um Livro |"<<endl;
                break;
            case '5': // Listar
                __CLEAR__;
                imprimirPrimeiroMenu();
                cout<<"LISTAR: n - Publicacoes | "
                <<"o - Emprestimos |"<<endl;
                break;
            case '6': // Carregar/Salvar
                __CLEAR__;
                imprimirPrimeiroMenu();
                cout<<"ARQUIVO: p - carregar de Arquivo | "
                <<"q - Salvar em Arquivo |"<<endl;
                break;
            case 'a': // cadastrarUsuario
                cout<<"Cadastrar Usuario"<<endl;
                cadastrarUsuario();
                break;
            case 'b': // cadastrarLivro
                cout<<"Cadastrar Livro"<<endl;
                cadastrarLivro();
                break;
            case 'c': // cadastrar Periodico
                cout<<"Cadastrar Periodico"<<endl;
                cadastrarPeriodico();
                break;
            case 'd': // cadastrarEmprestimo
                cout<<"Cadastrar Emprestimo"<<endl;
                cadastrarEmprestimo();
                break;
            
            case 'e': // excluirUsuario
                cout<<"Excluir Usuario"<<endl;
                excluirUsuario();
                break;
            case 'f': // excluirLivro
                cout<<"Excluir Livro"<<endl;
                excluirLivro();
                break;
            case 'g': // excluirPeriodico
                cout<<"Excluir Periodico"<<endl;
                excluirPeriodico();
                break;
            case 'h': // excluirEmprestimo
                cout<<"Excluir Emprestimo"<<endl;
                excluirEmprestimo();
                break;
            case 'i': // excluit item
                cout<<"Excluir Item"<<endl;
                excluirItem();
                break;
            
            case 'j': // pesquisarPublicacao
                cout<<"Pesquisar Publicacao"<<endl;
                pesquisarPublicacao();
                break;
            case 'k': // pesquisarLivroAutor
                cout<<"Pesquisar Livro por Autor"<<endl;
                pesquisarLivroAutor();
                break;
            
            
            case 'l': //devolverTodoEmprestimo 
                cout<<"Devolver Todo Emprestimo"<<endl;
                devolverTodoEmprestimo();
                break;
            case 'm': // devolverLivro
                cout<<"Devolver Livro"<<endl;
                devolverLivro();
                break;
            
            case 'n': // listarPublicacoes
                cout<<"Listar Publicacoes"<<endl;
                listarPublicacoes();
                break;
            case 'o': // listarEmprestimos
                cout<<"Listar Emprestimos"<<endl;
                listarEmprestimos();
                break;
            case 'p': // carregarArquivo
                cout<<"Carregar Dados de um Arquivo"<<endl;
                carregarArquivo();
                break;
            case 'q': // salvarArquivo
                cout<<"Salvar Dados num Arquivo"<<endl;
                salvarArquivo();
                break;
            default:
                __CLEAR__;
                imprimirPrimeiroMenu();
                break;
        } 
    }while(op!=27);
    __CLEAR__;
}
void Interface::carregarArquivo(){
    cout<<"Digite o nome do arquivo onde a ser carregado: "<<endl;
    string nome;
    cin>>nome;
    if (nome.find(string(".txt")) == string::npos){
       nome+=string(".txt"); 
    }
    cout<<"Biblioteca salva em: "<<nome<<endl;
    bib.lerArquivo(nome);
}
void Interface::imprimirPrimeiroMenu(){
    cout<<"Bilioteca"<<endl;
    cout<<"1 - Cadastrar | 2 - Excluir |"
    <<" 3 - Pesquisar  "<<endl
    <<"4 - Devolver  | 5 - Listar  | "
    <<"6 - Arquivo(Carregar/Salvar)  "<<endl
    <<"ESC - Sair    |"<<endl;
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