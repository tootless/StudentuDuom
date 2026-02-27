//Studentai struct function implementations

#include "struct.h"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

using std::cout;
using std::cin;

//DARBAS SU FAILU
//
void Studentas::read_file(std::string filename) {
	char v[13], p[14];

	//implement try catch
	std::fstream fin(filename, std::ios::in);

	fin.ignore(INT32_MAX, '\n');
	fin.getline(v, 13); vardas = v;
	fin.getline(p, 14); pav = p;

	cout << "VARDAS: " << vardas << "\n";
	cout << "PAVARDE: " << pav << "\n";
}

//DARBAS SU EKRANU
// 
//Vardo, pavardes ivestis
void Studentas::varpav_input()
{
	cout << "Iveskite studento varda: \n";
	cout << "Vardas: ";
	cin >> vardas;

	cout << "Iveskite studento pavarde: \n";
	cout << "Pavarde: ";
	cin >> pav;
	cout << "\n";
}

//Nd pazymiu ivestis
void Studentas::paz_input(int& suma)
{
	cout << "Iveskite studento pazymius:\n";

	int tempPaz;
	int choiceEndPaz = 0;

	do {
		input_validation(tempPaz, 1, 10, "Pazymys:\n");

		suma += tempPaz;
		paz.push_back(tempPaz);

		do {
			input_validation(choiceEndPaz, 0, 1, "\nAr vesite dar viena pazymi? (0 - Taip, 1 - Ne, eikime prie kito studento):\n");

		} while (choiceEndPaz < 0 || choiceEndPaz > 1);
	} while (choiceEndPaz != 1);
}

//Egzamino balo ivestis
void Studentas::egz_input()
{
	do {
		cout << "Iveskite studento egzamino bala: \n";
		cin >> egzaminas;

		if (cin.fail() || egzaminas < 1 || egzaminas > 10) {
			cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 1 iki 10---\n";

			//Reset cin buffer
			cin.clear();
			cin.ignore(1000, '\n');
		}

	} while (cin.fail() || egzaminas < 1 || egzaminas > 10);
}

//Randomizuoti nd pazymiai
void Studentas::rand_paz(int pazSk, int& suma) //pazSk -> vartotojo ivestas pazymiu kiekis
{
	for (int i = 0; i < pazSk; i++) {
		int tempPazRnd = rand() % 10 + 1;
		paz.push_back(tempPazRnd);

		suma += tempPazRnd;
	}

	cout << "Ivesti pazymiai:\n{ ";
	for (int i = 0; i < pazSk; i++) {
		cout << paz[i] << " ";
	}
	cout << "}";
}

//Randomizuotas egzamino balas
void Studentas::rand_egz()
{
	int tempEgzPazRnd = rand() % 10 + 1;
	egzaminas = tempEgzPazRnd;
	cout << "Ivestas egzamino balas:\n";
	cout << "{ " << tempEgzPazRnd << " }\n";
}

//Randomizuotas vardas ir pavarde
void Studentas::rand_stud()
{
	switch (rand() % 14) {
	case 0: vardas = "Irma"; break;
	case 1: vardas = "Alma"; break;
	case 2: vardas = "Irena"; break;
	case 3: vardas = "Egle"; break;
	case 4: vardas = "Jolanta"; break;
	case 5: vardas = "Petras"; break;
	case 6: vardas = "Jonas"; break;
	case 7: vardas = "Ignas"; break;
	case 8: vardas = "Darius"; break;
	case 9: vardas = "Simas"; break;
	case 10: vardas = "Aistis"; break;
	case 11: vardas = "Aurimas"; break;
	case 12: vardas = "Kotryna"; break;
	case 13: vardas = "Bertolomiejus"; break;
	case 14: vardas = "Augustinas"; break;
	}
	switch (*vardas.rbegin()) {
	case 's': //M
		switch (rand() % 14) {
		case 0: pav = "Kazlauskas"; break;
		case 1: pav = "Stankevicius"; break;
		case 2: pav = "Petrauskas"; break;
		case 3: pav = "Zukauskas"; break;
		case 4: pav = "Jankauskas"; break;
		case 5: pav = "Butkus"; break;
		case 6: pav = "Kirkliauskas"; break;
		case 7: pav = "Vasiliauskas"; break;
		case 8: pav = "Lukosius"; break;
		case 9: pav = "Vilkas"; break;
		case 10: pav = "Markevicius"; break;
		case 11: pav = "Maciulis"; break;
		case 13: pav = "Adomavicius"; break;
		case 14: pav = "Mickius"; break;
		}
		break;
	default: //F
		switch (rand() % 10) {
		case 0: pav = "Andziuliene"; break;
		case 1: pav = "Gaidyte"; break;
		case 2: pav = "Dirse"; break;
		case 3: pav = "Ciurlionaite"; break;
		case 4: pav = "Dunauskaite"; break;
		case 5: pav = "Dvarionaite"; break;
		case 6: pav = "Klumpaite"; break;
		case 7: pav = "Salnaite"; break;
		case 8: pav = "Vaitkute"; break;
		case 9: pav = "Mickeviciute"; break;
		case 10: pav = "Urbe"; break;
		}
		break;
	};

	cout << "\n\nCia yra vardas: " << vardas << ", o cia pavarde: " << pav << "\n\n\n";
}