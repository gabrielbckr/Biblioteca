#ifndef _USER_LIBRY_ 
#define _USER_LIBRY_

#include <string>
#include <iostream>
using namespace std;

class Usuario{
    string nome, cpf , endereco , fone , dataPenalizacao;
public:
    Usuario(string, string, string, string); // inicializa dataPenalizacao com data atual
    ~Usuario(){}

};


/* ESPESSIFICACAO */

/*Classe Usuário:
§ Atributos: string nome, cpf , endereco , fone  e Date dataPenalização 
§ Deve existir um método construtor que inicializa todos os atributos através de argumentos com exceção
do atributo dataPenalização. Este deve ser inicializado com a data corrente, sinalizando que o Usuário já
poderá tomar um novo empréstimo a partir de seu cadastro. O significado deste atributo será explicado
mais a frente.
*/
#endif