#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdlib.h>

// Var. 1; Visi duomenu rinkiniai su C masyvais

using std::cout;
using std::cin;

//Reiketu constructor, copy ir destructor nes dabar ypatingai nepatogu skaityti ir suprasti
struct Studentas {
	std::string vardas, pav;
	int pazKiekis = 0;
	int* paz = new int[2];
	int egzaminas = 0;
	double galutinis = 0; //Galutinis rezultatas

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
	void paz_input(int& suma, int& maxP)
	{
		if (pazKiekis >= maxP) {
			paz_check(maxP);
		}

		int tempPaz = 0;
		int choiceEndPaz = 0;

		do {
			cout << "Pazymys:\n";
			cin >> tempPaz;

			if (cin.fail() || tempPaz < 1 || tempPaz > 10) {
				cout << "\n---KLAIDA: Iveskite sveikaji skaiciu nuo 1 iki 10---\n";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				paz[pazKiekis] = tempPaz;
				suma += tempPaz;
				pazKiekis++;

				//Check end paz
				do {

					cout << "Ar vesite dar viena pazymi? (0 - Taip, 1 - Ne, eikime prie kito studento):\n";
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
	void rand_paz(int& suma, int& maxP)
	{
		if (pazKiekis >= maxP) {
			paz_check(maxP, pazKiekis);
		}

		for (int i = 0; i < pazKiekis; i++) {
			int tempPazRnd = rand() % 10 + 1;

			paz[i] = tempPazRnd;
			suma += tempPazRnd;
		}

		cout << "Ivesti pazymiai:\n{ ";
		for (int i = 0; i < pazKiekis; i++) {
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
		int randNum = rand() % 14;
		int randNum2 = rand() % 14;
		int randNum3 = rand() % 14;

		switch (randNum) {
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
		cout << "\n" << randNum << " vardas\n";
		switch (*vardas.rbegin()) {
		case 's': //M
			switch (randNum2) {
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
			switch (randNum2) {
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
			case 11: pav = "Snekuciovaite"; break;
			case 12: pav = "Argonaite"; break;
			case 13: pav = "Magdolena"; break;
			case 14: pav = "Durklaityte"; break;
			}
			break;
		};
		cout << randNum2 << " pavarde\n";


		cout << "\n\nIvestas vardas: " << vardas << ",\nIvesta pavarde: " << pav << "\n\n";
	}

	//Pazymiu masyvo dydzio patikrinimas / padidinimas
	void paz_check(int& maxP)
	{
		int newMaxPaz = maxP * 2; //Maksimalus pazymiu skaicius * 2
		int* newPaz = new int[newMaxPaz];

		for (int i = 0; i < pazKiekis; i++) {
			newPaz[i] = paz[i];
		}
		delete[] paz;


		paz = newPaz;
		maxP = newMaxPaz;

		cout << "\n MAX PAZ SIZE INCREASED: " << maxP << "\n"; // DEBUG
	}

	//Pazymiu masyvo dydzio patikrinimas / padidinimas su randomizuotu generavimu
	void paz_check(int& maxP, int pazSk)
	{

		int newMaxPaz = pazSk + 1; //Maksimalus pazymiu skaicius = ivestas pazymiu skaicius + 1, kadangi jis nesikeis
		int* newPaz = new int[newMaxPaz];

		for (int i = 0; i < pazKiekis; i++) {
			newPaz[i] = paz[i];
		}
		delete[] paz;


		paz = newPaz;
		maxP = newMaxPaz;

		cout << "\n MAX PAZ SIZE INCREASED: " << maxP << "\n"; // DEBUG
	}

};

void stud_check(Studentas*& Studentai, int currM, int& maxM) { //currM -> current stud count
	int newMaxM = maxM * 2; //Maksimalus studentu skaicius * 2
	Studentas* NewStudentai = new Studentas[newMaxM];

	for (int i = 0; i < currM; i++) {
		NewStudentai[i] = Studentai[i];
	}

	delete[] Studentai;
	Studentai = NewStudentai;
	maxM = newMaxM;

	cout << "\nMAX STUDENT COUNT INCREASED: " << maxM;
}

void menu(int& m) {
	cout << "\nMENIU\n";
	cout << "\n--------\n";
	cout << "Pasirinkite programos eiga " << m + 1 << "-am studentui:\n\n"
		<< "1 - Viskas ranka,\n2 - Randomizuoti nd. pazymiai ir egz. balas,\n3 - Viskas randomizuota,\n4 - Baigti darba (Ir isvesti galutinius rezultatus).";
	cout << "\n--------\n";
}

int main()
{
	int maxM = 2; //Pradinis maksimalus studentu skaicius
	int maxP = 2; //Pradinis maksimalus pazymiu skaicius;
	Studentas* Studentai = new Studentas[maxM]; //Galutiniai studentu duomenys
	int m = 0; //Studentu skaicius
	int suma = 0; //Pazymiu suma (Vidurkiui apskaiciuoti)
	double vidurkis = 0, mediana = 0;
	int choiceRez = 0; //Galutinio rez. isvedimo pasirinkimas
	int choiceEndStud = 0; //Studentu duomenu ivesties baigties pasirinkimas
	int choiceEndPaz = 0; //Pazymiu ivesties baigties pasirinkimas
	int choiceMenu = 0; //Pazymiu ivedimo / randomizavimo eigos pasirinkimas

	srand(time(NULL));

	///DUOMENU IVESTIS
	do {
		if (m < maxM) {
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

				//Studentai array check
				if (m >= maxM) {
					stud_check(Studentai, m, maxM);
				}
				Studentai[m].stud_input();

				cout << "---STUDENTO PAZYMIU IVEDIMAS---\n\n";

				Studentai[m].egz_input();

				cout << "Iveskite studento pazymius:\n";

				Studentai[m].paz_input(suma, maxP);
			}

			//RND PAZYMIAI IR EGZAMINO BALAS
			else if (choiceMenu == 2) {
				cout << "---STUDENTO DUOMENU IVEDIMAS---\n\n";

				Studentai[m].stud_input();

				cout << "\n---RANDOMIZUOTAS EGZAMINO BALAS---\n\n";

				Studentai[m].rand_egz();

				cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n\n";

				do {
					cout << "Iveskite norima namu darbu pazymiu skaiciu:";
					cin >> Studentai[m].pazKiekis;

					if (cin.fail() || Studentai[m].pazKiekis < 1) {
						cout << "\n---KLAIDA: Iveskite sveikaji skaiciu---\n";

						//Reset cin buffer
						cin.clear();
						cin.ignore(1000, '\n');
					}

				} while (Studentai[m].pazKiekis < 1);

				Studentai[m].paz_check(maxP, Studentai[m].pazKiekis);

				Studentai[m].rand_paz(suma, maxP);

			}

			//RND VISKAS
			if (choiceMenu == 3) {
				cout << "\n---RANDOMIZUOTAS STUDENTO VARDAS IR PAVARDE";
				Studentai[m].rand_stud();

				cout << "\n---RANDOMIZUOTAS EGZAMINO BALAS---\n\n";

				Studentai[m].rand_egz();

				cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n\n";

				do {
					cout << "Iveskite norima namu darbu pazymiu skaiciu:";
					cin >> Studentai[m].pazKiekis;

					system("cls");
					if (cin.fail() || Studentai[m].pazKiekis < 1) {
						cout << "\n---KLAIDA: Iveskite sveikaji skaiciu---\n";

						//Reset cin buffer
						cin.clear();
						cin.ignore(1000, '\n');
					}

				} while (Studentai[m].pazKiekis < 1);

				Studentai[m].rand_paz(suma, maxP);
			}

			//BAIGTI DARBA (Isvesti galutini rez jei yra)
			else if (choiceMenu == 4) {
				//Eiti i isvedima
				choiceEndStud = 1;
			}

			//Check if Studentai empty
			if (Studentai[m].vardas != "") {
				//Apskaiciuojame vidurki ir galutini rezultata kiekvienam studentui
				vidurkis = (double)suma / (double)Studentai[m].pazKiekis;
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
			vidurkis = 0;
			suma = 0;
		}
		else if (m >= maxM) {
			stud_check(Studentai, m, maxM);
		}

	} while (choiceEndStud != 1);

	///GALUTINIS REZULTATAS

	if (m == 0) {
		cout << "\nStudentu duomenu nera.\n\n";
		//Restart();
	}
	for (int i = 0; i < m; i++) {
		if (m != 0) //If !Studentai.empty
		{
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

			if (choiceRez == 1) { //Vidurkis
				cout << "\nPavarde     Vardas         Galutinis(Vid.)\n";
				cout << "------------------------------------------\n";
				for (int i = 0; i < m; i++) {
					cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << std::fixed << std::setprecision(2) << Studentai[i].galutinis << "\n";
				}

				choiceRez = 0;
				break;
			}
			else if (choiceRez == 2) { //Mediana
				//Rasti mediana

				std::sort(Studentai[i].paz, Studentai[i].paz + m);

				int midLeftElem = Studentai[i].pazKiekis / 2 - 1;
				int midElem = Studentai[i].pazKiekis / 2;

				if (Studentai[i].pazKiekis % 2 == 0) {
					mediana = (Studentai[i].paz[midLeftElem] + Studentai[i].paz[midElem]) / 2;
				}
				else {
					mediana = Studentai[i].paz[midElem];
				}

				Studentai[i].galutinis = 0.4 * mediana + 0.6 * Studentai[i].egzaminas;

				cout << "\nPavarde     Vardas         Galutinis(Med.)\n";
				cout << "------------------------------------------\n";
				for (int i = 0; i < m; i++) {
					cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << std::fixed << std::setprecision(2) << Studentai[i].galutinis << "\n";
				}

				choiceRez = 0;
				break;
			}
		}
	}

	return 0;
}