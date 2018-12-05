#include "Usuario.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "Periodico.hpp"
#include "ItemEmprestimo.hpp"   
#include <vector>

class Biblioteca{
    vector<Usuario> usuarios;
    vector<Publicacao> livros;
    vector<Emprestimo> emprestimos;
public:
    Biblioteca();// tudo vazio mesmo.
    void adicionarUsuario(Usuario);
    void adicionarPublicacao(Publicacao); 
    void adicionarEmprestimo(Emprestimo);
    void excluirUsuario(Usuario); // não pode ser excluído se existir algum empréstimo para ele
    void excluirEmprestimo(const Emprestimo);
    void exluirItemEmprestimo( Emprestimo, ItemEmprestimo);
    void obterUsuarios();
    void obterPublicacoes();
    void obterEmprestimos();
    void arquivarConteudo();
    void lerArquivo();
    void inserirItemEmprestimo(Emprestimo, ItemEmprestimo);
    void excluirPublicacao(Publicacao); // Se a publicação for um livro, este não pode ser excluído se existir algum empréstimo para ele;
    void devolverItem(Emprestimo, Livro);
    void devolverTodosItens(Emprestimo);
    vector<Publicacao*> buscaPublicacao(string);
    vector<Livro*> buscaLivroAutor(string);
};
