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
    void excluirEmprestmo(const Emprestimo);
    void exluirItemEmprestimo( Emprestimo, ItemEmprestimo);
    void obterUsuarios();
    void obterPublicacoes();
    void obteremprestimos();
    void arquivarConteudo();
    void lerArquivo();
    void inserirItemEmprestimo(Emprestimo, ItemEmprestimo);
    void excluirPublicacao(Publicacao); // Se a publicação for um livro, este não pode ser excluído se existir algum empréstimo para ele;
};
/*

§ Deve existir um método para devolver um item (livro) de um empréstimo. Argumento: o empréstimo e o
livro a ser devolvido.
§ Deve existir um método para devolver todos os livros de um empréstimo. Argumento: o empréstimo.
§ Deve existir um método para pesquisar publicações (livro ou periódico) por título. Argumento: uma string
especificando parte do título da publicação. O método deve retornar uma lista com todas as publicações
que contêm a string no título;
§ Deve existir um método para pesquisar livros por autor. Argumento: uma string especificando parte do
nome do autor. O método deve retornar uma lista com todos os livros que contêm a string no nome dos
autores;
*/