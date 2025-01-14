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

	void afiseaza() const
	{

		cout <<"Elevul \"" << nume << "\", in varsta de " << varsta << " ani, de la scoala/liceul \"" << scoala << "\", are adresa de email: " << gmail << "." << endl;

		if (nota != -1) {
			cout << "Nota la Informatica: " << nota << "\n";
		}
		else {
			cout << "Nota nu a fost încă alocată.\n";
		}
	
	}

};

