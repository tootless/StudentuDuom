#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <stdlib.h>

// Var. 2; Visi duomenu rinkiniai su std::vector

using std::cout;
using std::cin;

struct Studentas {
	std::string vardas, pav;
	std::vector<int> paz;
	int egzaminas = 0;
	double galutinis = 0;

	//Vardo, pavardes ivestis
	void stud_input()
	{
		cout << "Iveskite studento varda: \n";
		cout << "Vardas: ";
		cin >> vardas;

		cout << "Iveskite studento pavarde: \n";
		cout << "Pavarde: ";
		cin >> pav;
		cout << "\n";
	}

	//Nd pazymio ivestis
	void paz_input(int& suma)
	{
		cout << "Iveskite studento pazymius:\n";

		int tempPaz;
		int choiceEndPaz = 0;

		do {
			cout << "Pazymys:\n";
			cin >> tempPaz;

			//Check pazymys
			if (cin.fail() || tempPaz < 1 || tempPaz > 10) {
				cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 1 iki 10---\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				suma += tempPaz;
				paz.push_back(tempPaz);

				//Check end paz
				do {
					cout << "\nAr vesite dar viena pazymi? (0 - Taip, 1 - Ne, eikime prie kito studento): \n";
					cin >> choiceEndPaz;

					if (cin.fail() || (choiceEndPaz != 0 && choiceEndPaz != 1)) {
						cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 0 iki 1---\n";
						cin.clear();
						cin.ignore(1000, '\n');
						choiceEndPaz = -1;
					}
				} while (cin.fail() || (choiceEndPaz != 0 && choiceEndPaz != 1));
			}
		} while (choiceEndPaz != 1);
	}

	//Egzamino balo ivestis
	void egz_input()
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
	void rand_paz(int pazSk, int& suma) //pazSk -> vartotojo ivestas pazymiu kiekis
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
	void rand_egz()
	{
		int tempEgzPazRnd = rand() % 10 + 1;
		egzaminas = tempEgzPazRnd;
		cout << "Ivestas egzamino balas:\n";
		cout << "{ " << tempEgzPazRnd << " }\n";
	}

	//Randomizuotas vardas ir pavarde
	void rand_stud()
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
};

void menu(int& m) {
	cout << "\nMENIU\n";
	cout << "\n--------\n";
	cout << "Pasirinkite programos eiga " << m + 1 << "-am studentui:\n\n"
		<< "1 - Viskas ranka,\n2 - Randomizuoti nd. pazymiai ir egz. balas,\n3 - Viskas randomizuota,\n4 - Baigti darba (Ir isvesti galutinius rezultatus).";
	cout << "\n--------\n";
}

int main()
{
	Studentas A; //Temp studentas su realiais duomenimis
	std::vector<Studentas> Studentai; //Galutiniai studentu duomenys
	int n = 0; //Pazymiu kiekis;
	int m = 0; //Studentu skaicius
	int suma = 0; //Pazymiu suma (Vidurkiui apskaiciuoti)
	double vidurkis = 0, mediana = 0;
	int choiceRez = 0; //Galutinio rez. isvedimo pasirinkimas
	int choiceEndStud = 0; //Studentu duomenu ivesties baigties pasirinkimas
	int choiceMenu = 0; //Programos eigos pasirinkimas

	srand(time(NULL));

	do {

		//MENIU
		do {
			menu(m);

			cin >> choiceMenu;

			system("cls");

			if (cin.fail() || choiceMenu < 1 || choiceMenu > 4) {
				cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 1 iki 4---\n";

				//Reset cin buffer
				cin.clear();
				cin.ignore(1000, '\n');
				choiceMenu = 0;
			}

		} while (choiceMenu < 1 || choiceMenu > 4);

		//RANKA
		if (choiceMenu == 1) {
			cout << "---STUDENTO DUOMENU IVEDIMAS---\n\n";

			A.stud_input();

			cout << "---STUDENTO PAZYMIU IVEDIMAS---\n\n";

			A.egz_input();

			A.paz_input(suma);
		}

		//RND PAZYMIAI IR EGZAMINO BALAS
		else if (choiceMenu == 2) {
			cout << "---STUDENTO DUOMENU IVEDIMAS---\n\n";

			A.stud_input();

			cout << "\n---RANDOMIZUOTAS EGZAMINO BALAS---\n\n";

			A.rand_egz();

			cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n\n";

			do {
				cout << "Iveskite norima namu darbu pazymiu skaiciu:";
				cin >> n;

				system("cls");
				if (cin.fail() || n < 1) {
					cout << "\n---KLAIDA: Iveskite sveikaji skaiciu---\n";

					//Reset cin buffer
					cin.clear();
					cin.ignore(1000, '\n');
				}

			} while (n < 1);

			A.rand_paz(n, suma);
		}

		//RND VISKAS
		else if (choiceMenu == 3) {
			cout << "\n---RANDOMIZUOTAS STUDENTO VARDAS IR PAVARDE";
			A.rand_stud();

			cout << "\n---RANDOMIZUOTAS EGZAMINO BALAS---\n\n";

			A.rand_egz();

			cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n\n";

			do {
				cout << "Iveskite norima namu darbu pazymiu skaiciu:";
				cin >> n;

				if (cin.fail() || n < 1) {
					cout << "\n---KLAIDA: Iveskite sveikaji skaiciu---\n";

					//Reset cin buffer
					cin.clear();
					cin.ignore(1000, '\n');
				}

			} while (n < 1);

			A.rand_paz(n, suma);
		}

		//BAIGTI DARBA (Isvesti galutini rez jei yra)
		else if (choiceMenu == 4) {
			//Eiti i isvedima
			choiceEndStud = 1;
		}

		//Perkeliam vieno studento duomenis
		Studentai.push_back(A);
		if (!Studentai.empty()) {
			//Apskaiciuojame vidurki ir galutini rezultata su juo kiekvienam studentui
			vidurkis = (double)suma / ((double)Studentai[m].paz.size());
			Studentai[m].galutinis = 0.4 * vidurkis + 0.6 * Studentai[m].egzaminas;
		}

		if (choiceMenu != 4) {
			m++; //Skaiciuojame studentu skaiciu / saugome indeksa
			do {
				cout << "\nAr vesite dar vieno studento duomenis? (0 - Taip, 1 - Ne, einame prie galutiniu rezultatu)\n";
				cin >> choiceEndStud;

				system("cls");
				if (choiceEndStud != 0 && choiceEndStud != 1) {
					cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 0 iki 1.---\n";
				}

			} while (choiceEndStud != 0 && choiceEndStud != 1);
		}

		//Reset
		system("cls");
		vidurkis = 0;
		suma = 0;
		n = 0;
	} while (choiceEndStud != 1);

	///GALUTINIS REZULTATAS
	if (!Studentai.empty()) {

		do {
			cout << "Kaip norite isvesti studentu galutinius rezultatus? (1 - Vidurkis, 2 - Mediana)\n";
			cin >> choiceRez;

			system("cls");
			if (choiceRez != 1 && choiceRez != 2) {
				cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 1 iki 2.---\n";
				
				//Reset cin buffer
				cin.clear();
				cin.ignore(1000, '\n');
				choiceRez = 0;
			}

		} while (choiceRez != 1 && choiceRez != 2);

		//VIDURKIS
		if (choiceRez == 1) {
			cout << "\nPavarde     Vardas         Galutinis(Vid.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << std::fixed << std::setprecision(2) << Studentai[i].galutinis << "\n\n";
			}
			choiceRez = 0;
		}
		//MEDIANA
		else if (choiceRez == 2) {
			//Rasti mediana
			for (int i = 0; i < m; i++) {
				int a = Studentai[i].paz.size();
				sort(Studentai[i].paz.begin(), Studentai[i].paz.end());
				if (a % 2 == 0) {
					int midLeftElem = a / 2 - 1;
					mediana = (Studentai[i].paz[midLeftElem] + Studentai[i].paz[a / 2]) / 2;
				}
				else
					mediana = Studentai[i].paz[a / 2];

				Studentai[i].galutinis = 0.4 * mediana + 0.6 * Studentai[i].egzaminas;
			}

			cout << "\nPavarde     Vardas         Galutinis(Med.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << std::fixed << std::setprecision(2) << Studentai[i].galutinis << "\n\n";
			}

			choiceRez = 0;
		}

		//Restart()
	}
	else if (Studentai.empty()) {
		cout << "Studentu duomenu nera.\n\n";
		//Restart();
	}

	return 0;
}
