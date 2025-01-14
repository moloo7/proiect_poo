#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "student.h"
#include "premiu.h"
#include "proba.h"
#include <cstdlib> 
#include <ctime>

using namespace std;

int main()
{
	vector<Student> studenti;
	srand(time(0));

	Premiu premiul1("O vacanta\n", "Un laptop\n", "Un ceas\n", "RESTUL LOCURILOR PRIMESC MENTIUNE , MULTUMIM TUTUROR PENTRU PARTICIPARE\n");
	Probe probe("Informatia", "Facultatea de Automatica, Calculatoare si Electronica, CRAIOVA", "15 Ianuarie 2025", 10);
	

	string nume_elev, gmail_elev, scoala_de_provenienta;
	int varsta_elev;

	int optiune;

	do
	{

		cout << "\n";
		cout << " ========== MENIU ==========\n";
		cout << "\n";
		cout << " 1. Inscrieti-va la concurs!\n";
		cout << " 2. Afisati concurentii inscrisi la concurs!\n";
		cout << " 3. Cautati un elev dupa nume/cod!\n";
		cout << " 4. Afisati datele concursului!  \n";
		cout << " 5. Afisati notele obtinute de catre elevi!\n";
		cout << " 6. Afisati lista premiilor concursului!\n";
		cout << " 7. Afisati rezultatele concursului!\n";
		cout << " 8. Iesiti!\n";
		cout << "\n";
		cout << " ALEGETI OPTIUNEA DORITA! : ";

		cin >> optiune;

		switch (optiune)
		{
		case 1:

			int codUnic;
			cout << "Introduceti numele elevului: ";
			cin >> ws;
			getline(cin, nume_elev);
			cout << "Varsta elevului: ";
			cin >> varsta_elev;
			cout << "Gamil-ul elev: ";
			cin >> ws;
			getline(cin, gmail_elev);
			cout << "Scoala elevului de porvenienta: ";
			cin >> ws;
			getline(cin, scoala_de_provenienta);

			codUnic = rand() % 9000 + 1000;
			studenti.emplace_back(nume_elev, varsta_elev, gmail_elev, scoala_de_provenienta, codUnic);
			cout << "\nEleul a fost introdus cu succes! COD UNIC: " << codUnic << "\n";
			break;

		case 2:

			if (studenti.empty())
			{
				cout << "\nNu exista elevi inscrisi!\n";
			}
			else
			{
				cout << "\nLista elevilor inscrisi : \n";
				for (const auto& student : studenti)
				{
					cout << "Elevul: " << student.getNume()
						<< " (COD: " << student.getCodUnic() << ")\n";
				}
			}
			break;

		case 3:

			if (studenti.empty())
			{
				cout << "\nNu exista elevi inscrisi!\n";
				break;
			}

			int criteriu;
			cout << "Cautati dupa:\n";
			cout << "1. Nume\n";
			cout << "2. COD\n";
			cout << "Introduceti optiunea dorita: ";
			cin >> criteriu;

			if (criteriu == 1)
			{
				string numeCautat;
				cout << "Introduceti numele elevului: ";
				cin >> ws;
				getline(cin, numeCautat);

				bool gasit = false;
				for (const auto& student : studenti)
				{
					if (student.getNume() == numeCautat)
					{
						cout << "Elev gasit:\n";
						student.afiseaza();
						gasit = true;
						break;
					}
				}

				if (!gasit) {
					cout << "Nu a fost gasit niciun elev cu acest nume.\n";
				}

			}
			else if (criteriu == 2)
			{
				int cpdCautat;
				cout << "Introduceti COD-ul elevului: ";
				cin >> cpdCautat;

				bool gasit = false;
				for (const auto& student : studenti)
				{
					if (student.getCodUnic() == cpdCautat)
					{
						cout << "Elev gasit:\n";
						student.afiseaza();
						gasit = true;
						break;
					}
				}

				if (!gasit) {
					cout << "Nu a fost gasit niciun elev cu acest COD.\n";
				}

			}
			else
			{
				cout << "Optiune invalida.\n";
			}

			break;


		case 4:

			probe.afiseaza();
			break;

		case 5:

			if (studenti.empty()) {
				cout << "\nNu exista elevi inscrisi!\n";
			}
			else {
				cout << "\nLista rezultatelor elevilor:\n";
				for (auto& student : studenti) {
					if (student.getNota() == -1) {
						double nota = 6.5 + static_cast<double>(rand()) / (RAND_MAX / 3.5);
						student.setNota(nota);
					}
					cout << "Elevul: " << student.getNume()
						<< " (COD: " << student.getCodUnic() << ")\n";
					cout << "Nota obtinuta la Informatica: " << student.getNota() << "\n\n";
				}
			}
			break;

		case 6:

			cout << "\n";
			cout << premiul1;
			break;

		default:
			cout << "\nOptiune invalida , introduceti un numar cuprins intre 1-5 :\n";
			break;


		case 7:
			if (studenti.empty())
			{
				cout << "\nNu exista elevi inscrisi!\n";
			}
			else
			{
				cout << "\nLista premiilor obtinute de elevi:\n";
				for (const auto& student : studenti)
				{
					double nota = student.getNota();
					if (nota == -1)
					{
						cout << "Elevul " << student.getNume()
							<< " (COD: " << student.getCodUnic()
							<< ") nu are nota asignata.\n";
						continue;
					}

					cout << "Elevul: " << student.getNume()
						<< " (COD: " << student.getCodUnic() << ")\n";
					cout << "Nota obtinuta: " << nota << "\n";

					if (nota >= 9.5)
					{
						cout << "Premiul: O vacanta\n\n";
					}
					else if (nota >= 8.5)
					{
						cout << "Premiul: Un laptop\n\n";
					}
					else if (nota >= 7.5)
					{
						cout << "Premiul: Un ceas\n\n";
					}
					else
					{
						cout << "Premiul: Mentiune. Multumim pentru participare!\n\n";
					}
				}
			}
			break;

		case 8:

			cout << " Ati iesit din meniu!\n";

		}
	} while (optiune != 8);

	return 0;
}
