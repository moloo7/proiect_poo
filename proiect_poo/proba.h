#pragma once

#include <iostream>
#include <string>

using namespace std;

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