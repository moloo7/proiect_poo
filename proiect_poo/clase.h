#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student
{
private:

	double nota = 6.5 + static_cast<double>(rand()) / (RAND_MAX / 3.5);
	string nume;
	int varsta;
	string gmail;
	string scoala;
	int codUnic;

public:

	double getNota() const {
		return nota;
	}
	void setNota(double notaNoua) {
		nota = notaNoua; 
	}

	Student(string nume, int varsta, string gmail, string scoala, int codUnic)
	{
		this->nume = nume;
		this->varsta = varsta;
		this->gmail = gmail;
		this->scoala = scoala;
		this->codUnic = codUnic;
	}
	string getNume() const {

		return nume;
	}
	int getVarsta() const {

		return varsta;
	}
	string getGmail() const {

		return gmail;
	}
	string getScoala() const {

		return scoala;
	}
	int getCodUnic() const {

		return codUnic;
	}

	void afiseaza() const {

		cout <<"Elevul \"" << nume << "\", in varsta de " << varsta << " ani, de la scoala/liceul \"" << scoala << "\", are adresa de email: " << gmail << "." << endl;

		if (nota != -1) {
			cout << "Nota la Informatica: " << nota << "\n";
		}
		else {
			cout << "Nota nu a fost încă alocată.\n";
		}
	
	}

};

class Premiu
{

public:

	string premiu1;
	string premiu2;
	string premiu3;
	string mentiuni;

	Premiu(string premiu1, string premiu2, string premiu3, string mentiuni)
	{
		this->premiu1 = premiu1;
		this->premiu2 = premiu2;
		this->premiu3 = premiu3;
		this->mentiuni = mentiuni;
	}
};

static ostream& operator<<(ostream& os, const Premiu& premiu)
{
	os << "Premiul 1: " << premiu.premiu1;
	os << "Premiul 2: " << premiu.premiu2;
	os << "Premiul 3: " << premiu.premiu3;
	os << premiu.mentiuni;
	return os;
}

class Probe
{
public:

	string proba;
	string locatie;
	string data;
	double ora;

	Probe(string proba, string locatie, string data, double ora)
	{
		{
			this->proba = proba;
			this->locatie = locatie;
			this->data = data;
			this->ora = ora;

		}
	}


	string getProba1() const
	{
		return proba;
	}

	string getLocatie() const
	{
		return locatie;
	}

	string getData() const
	{
		return data;
	}

	double getOra() const
	{
		return ora;
	}


	void afiseaza() const
	{
		cout << "\nProba concursului:\n";
		cout << proba << endl;
		cout << "Locatia concursului se afla la " << locatie << ", Data: " << data << endl;
		cout << "Ora: " << ora << " AM" << endl;
	}

};
