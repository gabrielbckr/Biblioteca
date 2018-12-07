#include "Usuario.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Periodico.hpp"
#include "ItemEmprestimo.hpp"   
#include "myVector.hpp"

class Biblioteca{
    myVector<Usuario> usuarios;
    myVector<Publicacao> livros;
    myVector<Emprestimo> emprestimos;
public:
    Biblioteca();// tudo vazio mesmo.
    bool adicionarUsuario(Usuario);
    bool adicionarPublicacao(Publicacao); 
    Biblioteca& adicionarEmprestimo(Emprestimo);
    Biblioteca& excluirUsuario(Usuario); // não pode ser excluído se existir algum empréstimo para ele
    Biblioteca& excluirEmprestimo(const Emprestimo);
    Biblioteca& exluirItemEmprestimo( Emprestimo, ItemEmprestimo);
    myVector<Usuario>& obterUsuarios();
    myVector<Publicacao>& obterPublicacoes();
    myVector<Emprestimo>& obterEmprestimos();
    Biblioteca& arquivarConteudo();
    Biblioteca& lerArquivo();
    Biblioteca& inserirItemEmprestimo(Emprestimo, ItemEmprestimo);
    Biblioteca& excluirPublicacao(Publicacao); // Se a publicação for um livro, este não pode ser excluído se existir algum empréstimo para ele;
    Biblioteca& devolverItem(Emprestimo, Livro);
    Biblioteca& devolverTodosItens(Emprestimo);
    myVector<Publicacao*> buscaPublicacao(string);
    myVector<Livro*> buscaLivroAutor(string);
};
