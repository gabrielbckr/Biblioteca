#include "Usuario.hpp"

Usuario::Usuario(Usuario& U){
    nome = U.nome;
    cpf=U.cpf;
    endereco=U.endereco;
    fone=U.fone;
    dataPenalizacao = U.dataPenalizacao;
}
Usuario& Usuario::operator=(const Usuario& U){
    nome = U.nome;
    cpf=U.cpf;
    endereco=U.endereco;
    fone=U.fone;
    dataPenalizacao = U.dataPenalizacao;
    return *this;
}
Usuario& Usuario::mostrar(){
    cout<<"Nome: "           <<nome<<endl;
    cout<<"CPF: "            <<cpf<<endl;
    cout<<"Endereco: "       <<endereco<<endl;
    cout<<"Fone: "           <<fone<<endl;
    cout<<"DataPenalizacao: "<<dataPenalizacao<<endl;
    return *this;
}
bool Usuario::operator==(const Usuario& U) const{
    if (nome != U.nome){return false;}
    return (cpf == U.cpf) ;
}
ostream& operator<<(ostream& os, Usuario& U){
    os<<U.nome<<endl;
    os<<U.cpf<<endl;
    os<<U.endereco<<endl;
    os<<U.fone<<endl;
    os<<U.dataPenalizacao<<endl;
    return os;
}
istream& operator>>(istream& is, Usuario& U){
    string line;
    getline(is,line);
    U.setarNome(line);
    getline(is,line);
    U.setarCpf(line);
    getline(is,line);
    U.setarEndereco(line);
    getline(is,line);
    U.setarFone(line);
    getline(is,line);
    U.setarDataPen(line);
    return is;
}