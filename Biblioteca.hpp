#include "Usuario.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Periodico.hpp"
#include "ItemEmprestimo.hpp"   
#include "myVector.hpp"

class Biblioteca{
    myVector<Usuario> usuarios;
    myVector<Livro> livros;
    myVector<Periodico> periodicos;
    // myVector<Publicacao> publicacoes;
    myVector<Emprestimo> emprestimos;
public:
    Biblioteca();// tudo vazio mesmo.
    Biblioteca& adicionarUsuario(Usuario&);
    Biblioteca& adicionarPublicacao(Publicacao*);
    Biblioteca& adicionarLivro(Livro&); 
    Biblioteca& adicionarPeriodico(Periodico&);
    Biblioteca& adicionarEmprestimo(Emprestimo&);
    Biblioteca& excluirUsuario(Usuario&); // não pode ser excluído se existir algum empréstimo para ele
    Biblioteca& excluirEmprestimo(const Emprestimo);
    Biblioteca& exluirItemEmprestimo( Emprestimo, ItemEmprestimo);
    myVector<Usuario>& obterUsuarios();
    myVector<Publicacao*>& obterPublicacoes();
    myVector<Livro>& obterLivros();
    myVector<Periodico>& obterPeriodicos();
    myVector<Emprestimo>& obterEmprestimos();
    Biblioteca& arquivarConteudo(string&);
    Biblioteca& lerArquivo(string&);
    Biblioteca& inserirItemEmprestimo(Emprestimo, ItemEmprestimo);
    Biblioteca& excluirPublicacao(Publicacao*); // Se a publicação for um livro, este não pode ser excluído se existir algum empréstimo para ele;
    Biblioteca& devolverItem(Emprestimo, Livro);
    Biblioteca& devolverTodosItens(Emprestimo);
    myVector<Publicacao*>& buscaPublicacao(const string&);
    myVector<Livro>& buscaLivroAutor(const string&);
};
