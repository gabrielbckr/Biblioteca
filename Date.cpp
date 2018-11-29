#include "Date.hpp"

// expressao regular para avaliar validade de uma data no formato dd/mm/yyyy
// ver https://regexr.com/3b9td (adaptado)
const regex Date::re("(^(((0[1-9]|1[0-9]|2[0-8])[/](0[1-9]|1[012]))|((29|30|31)[/](0[13578]|1[02]))|((29|30)[/](0[4,6,9]|11)))[/](19|[2-9][0-9])[[:digit:]][[:digit:]]$)|(^29[/]02[/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)");

//http://www.cplusplus.com/articles/2wA0RXSz/
const vector<string> Date::explode(const string& s, const char& c) {
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if (buff != "") v.push_back(buff);

	return v;
}

bool Date::testaConsistencia(const string& s, time_t* d) {
	vector<string> tokens{ explode(s, '/') };
	int dia, mes, ano;
	string dia_s = tokens[0];
	string mes_s = tokens[1];
	string ano_s = tokens[2];
	if (s.size() == 10 && tokens.size() == 3 && tokens[0].size() == 2 && tokens[1].size() == 2 && tokens[2].size() == 4) {
        dia = stoi(dia_s);
		mes = stoi(mes_s);
		ano = stoi(ano_s);
		struct tm dataStruct = {0};
		dataStruct.tm_isdst = -1;
		dataStruct.tm_mday = dia;
		dataStruct.tm_mon = mes;
		dataStruct.tm_year = ano;
		time_t aux = mktime(&dataStruct);
		if (aux == -1) return false;
		if (d != nullptr) d = &aux;
		return true;
	}
	return false;
}

time_t Date::stringToTime(const string& s) {
	vector<string> tokens{ explode(s, '/') };
	int dia, mes, ano;
	dia = stoi(tokens[0]);
	mes = stoi(tokens[1]);
	ano = stoi(tokens[2]);
	struct tm dataStruct = {0};
	dataStruct.tm_isdst = -1;
	dataStruct.tm_mday = dia;
	dataStruct.tm_mon = mes;
	dataStruct.tm_year = ano;
	time_t aux = mktime(&dataStruct);
	if (aux != -1) return aux;
	else throw "falha na conversao";
}

Date::Date() {
	char aux[11];
	time_t Agora = time(0); // recebe a hora de agora
	size_t numCharConv = strftime(aux, 11, "%d/%m/%Y", localtime(&Agora)); // converte uma estrutura de hora para string em formato dd/mm/yyyy e retorna o numero de caracteres convertidos
	if (numCharConv > 0) dataString = aux; // se 0, o numero de caracteres foi excedido
	else throw "a conversao da data para string falhou";
}
Date::Date(const string& ds) {
	if (regex_match(ds, Date::re))
		dataString = ds;
	else throw "data invalida";
}
const string Date::pegarData() const {
	return dataString;
}
void Date::adicionarDias(const int& dias) {
	long int segundos = dias * 86400; // dias * 24 * 60 * 60
	struct tm dataStruct = {0};
	dataStruct.tm_isdst = -1;
	time_t dataT = mktime(&dataStruct);
	dataT += static_cast<time_t> (segundos); // acrescenta os dias em segundos a data atual
	char aux[11];
	size_t numCharConv = strftime(aux, 11, "%d/%m/%Y", localtime(&dataT)); // converte uma estrutura de hora para string em formato dd/mm/yyyy e retorna o numero de caracteres convertidos
	if (numCharConv > 0) dataString = aux; // se 0, o numero de caracteres foi excedido
	else throw "maximo de caracteres excedido";
}
ostream& operator<< (ostream& out, const Date& d) {
	out << d.dataString;
	return out;
}
istream& operator>> (istream& in, Date& d) {
	char s[11];
	in.getline(s, 11);
	if (regex_match(s, Date::re)) {
		d.dataString = s;
	}
	else throw "data invalida";
	return in;
}
Date::~Date() {}
