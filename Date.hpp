#ifndef _DATE_H__
#define _DATE_H__

#include <ctime>
#include <string>
#include <regex>
#include <vector>

using namespace std;

class Date {
	string dataString;
	time_t data;
	static const vector<string> explode(const string&, const char&);
public:
	static bool testaConsistencia(const string&, time_t* = nullptr);
	static const regex re;
	Date(); // constroi um Date com a hora de agora
	Date(const string&); // constroi um Date com a hora passada por string em formato dd/mm/yyyy
	const string pegarData() const; // retorna string dd/mm/yyyy
	void adicionarDias(const int&); // adiciona dias
	friend ostream& operator<< (ostream&, const Date&);
	friend istream& operator>> (istream& in, Date& d);
	~Date();
};

#endif
