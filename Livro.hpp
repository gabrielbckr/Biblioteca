#ifndef _LIVRO_LIBRY_
#define _LIVRO_LIBRY_

#include <string>
#include "Publicacao.hpp"
using namespace std;

class Livro: public Publicacao{
    string autores;
    int qtdeExemplares;
public:
    Livro(string tit, string ed, int  a , int cod, string aut,
          int qtde = 0):Publicacao(tit, ed , a , cod),
                        autores(aut), qtdeExemplares(qtde){}
    Livro& operator++(int){qtdeExemplares++;}
    ~Livro();
};

/*Classe Livro:
§ Atributos: autores (string, nome de todos os autores) e qtdeExemplares (int);
§ Deve existir um método construtor que inicializa todos os atributos através de parâmetros;
§ Deve existir um método construtor que inicializa os atributos codPublicacao, titulo, editora, ano e autores
através de argumentos e o atributo qtdeExemplares com zero;
§ Deve existir métodos para incrementar e decrementar a quantidade de exemplares de uma unidade; Não
permitir o decremento se a quantidade for igual a zero.*/

#endif