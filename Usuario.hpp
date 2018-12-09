#ifndef _USER_LIBRY_
#define _USER_LIBRY_

#include "Date.hpp"
#include <string>
#include <iostream>

using namespace std;

class Usuario{
    string nome, cpf, endereco, fone;
    Date dataPenalizacao;
public:
    Usuario(const string& n = string("def"), const string& c = string("def"),
        const string& e = string("def"), const string& f = string("def")) :
        nome(n), cpf(c), endereco(e), fone(f), dataPenalizacao(Date()) {} // inicializa dataPenalizacao com data atual
    Usuario(const Usuario&);
    const string pegarNome() const { return nome; }
    const string pegarCpf() const { return cpf; }
    const string pegarEndereco() const { return endereco; }
    const string pegarFone() const { return fone; }
    const Date pegarDataPen() const { return dataPenalizacao; }
    Usuario& setarNome(const string& N) { nome = N;  return *this;}
    Usuario& setarCpf(const string& C) { cpf = C;  return *this;}
    Usuario& setarEndereco(const string& E) { endereco = E;  return *this;}
    Usuario& setarFone(const string& F) { fone = F;  return *this;}
    Usuario& setarDataPen(const Date& D) { dataPenalizacao = D; return *this;}
    Usuario&  mostrar();
    Usuario& operator=(const Usuario&);
    bool operator==(const Usuario&) const;
    friend ostream& operator<<(ostream&, const Usuario&);
    friend istream& operator>>(istream&, Usuario&);
    ~Usuario(){}

};

#endif
