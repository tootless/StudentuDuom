//Function implementations

#include "functions.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using std::cout;
using std::cin;


//STRUCT STUDENTAI FUNKCIJOS

//DARBAS SU FAILU
//
std::vector<Studentas> Studentas::read_file(const std::string filename, int& suma) {
	std::vector<Studentas> tempStudentai;

	//implement try catch for if file not opening or file not found or...
	std::fstream fin(filename, std::ios::in);
	std::string curr_eil; //current eilute
	std::istringstream iss(curr_eil);

	fin.ignore(INT32_MAX, '\n');

	while (std::getline(fin, curr_eil)) {
		Studentas A; //temp Studentas
		int tempPaz;
		
		std::istringstream iss(curr_eil);
		iss >> A.vardas >> A.pav;

		//read visus pazymius
		while (iss >> tempPaz) {
			A.paz.push_back(tempPaz);
			suma += tempPaz;
		}
		//paskutinis pazymys paz vector yra egzamino balas
		A.egzaminas = A.paz.back();
		A.paz.pop_back();

		//apskaiciuoti galutinius rezultatus, kadangi isvedami abu
		double vidurkis = (double)suma / (double)A.paz.size();
		A.galutinisVid = 0.4 * vidurkis + 0.6 * A.egzaminas;

		int a = A.paz.size();
		double mediana;
		sort(A.paz.begin(), A.paz.end());
		if (a % 2 == 0) {
			int midLeftElem = a / 2 - 1;
			mediana = (A.paz[midLeftElem] + A.paz[a / 2]) / 2;
		}
		else
			mediana = A.paz[a / 2];

		A.galutinisMed = 0.4 * mediana + 0.6 * A.egzaminas;



		tempStudentai.push_back(A);

		suma = 0;
	}

	fin.close();

	return tempStudentai;
}

void Studentas::write_file(const std::string filename, const std::vector<Studentas>& Studentai) {
	std::ofstream fout(filename);

	fout << "\n" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)   Galutinis (Med.)" << "\n";
	fout << "----------------------------------------------------\n";
	for (const auto& s : Studentai) {
		fout << std::setw(15) << std::left << s.pav << std::setw(15) << std::left << s.vardas << std::setw(15) << std::left << std::fixed << std::setprecision(2) << s.galutinisVid << "   " << std::fixed << std::setprecision(2) << s.galutinisMed << "\n";
	}


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

//GLOBALIOS FUNKCIJOS
void menu() {
	cout << "\nMENIU\n";
	cout << "\n--------\n";
	cout << "Pasirinkite programos eiga\n\n"
		<< "1 - Viskas ranka,\n2 - Randomizuoti nd. pazymiai ir egz. balas,\n3 - Viskas randomizuota,\n4 - Baigti darba (Ir isvesti galutinius rezultatus),\n5 - Skaityti visus duomenis is failo.";
	cout << "\n--------\n";
}

void input_validation(int& choice, int lowEnd, int highEnd, std::string optionalPrompt) //if highEnd = -1, no highEnd used
{
	cout << optionalPrompt;

	cin >> choice;

	if (cin.fail() || choice < lowEnd || (choice > highEnd && highEnd != -1)) {
		//Check if highEnd used
		if (highEnd != -1) cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo " << lowEnd << " iki " << highEnd << "---\n";
		else if (highEnd == -1) cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo " << lowEnd << "---\n";

		//Reset cin buffer
		cin.clear();
		cin.ignore(1000, '\n');
	}
}