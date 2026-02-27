#include "mylib.h"
#include "functions.h"
#include "struct.h"

//Visi duomenu rinkiniai su std::vector

using std::cout;
using std::cin;

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

	srand(static_cast<unsigned int>(time(NULL)));

	do {

		//MENIU
		do {
			menu();

			input_validation(choiceMenu, 1, 5);

			system("cls");

		} while (choiceMenu < 1 || choiceMenu > 5);

		//RANKA
		if (choiceMenu == 1) {
			cout << "---STUDENTO DUOMENU IVEDIMAS---\n\n";

			A.varpav_input();

			cout << "---STUDENTO PAZYMIU IVEDIMAS---\n\n";

			A.egz_input();

			A.paz_input(suma);
		}

		//RND PAZYMIAI IR EGZAMINO BALAS
		else if (choiceMenu == 2) {
			cout << "---STUDENTO DUOMENU IVEDIMAS---\n\n";

			A.varpav_input();

			cout << "\n---RANDOMIZUOTAS EGZAMINO BALAS---\n\n";

			A.rand_egz();

			cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n\n";

			do {
				input_validation(n, 1, -1, "Iveskite norima namu darbu pazymiu skaiciu:\n");

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
				input_validation(n, 1, -1, "Iveskite norima namu darbu pazymiu skaiciu:");

			} while (n < 1);

			A.rand_paz(n, suma);
		}

		//BAIGTI DARBA (Isvesti galutini rez jei yra)
		else if (choiceMenu == 4) {
			//Eiti i isvedima
			choiceEndStud = 1;
		}

		//SKAITYTI IS FAILO
		else if (choiceMenu == 5) {
			std::string answer;
			int choiceOutput;
			cout << "---STUDENTO DUOMENU NUSKAITYMAS IS FAILO---\n\n";

			cout << "\nIveskite failo pavadinima, is kurio norite nuskaityti:\n";
			cin >> answer;
			Studentai = Studentas::read_file(answer, suma);

			//Isvedimas
			do {
				input_validation(choiceOutput, 1, 2, "Kur norite isvesti studentu galutinius rezultatus? (1 - Faile, 2 - Ekrane)\n");

			} while (choiceOutput < 1 || choiceOutput > 2);

			if (choiceOutput == 1) {
				std::string answer2;
				cout << "\nIveskite failo pavadinima, i kuri norite irasyti duomenis:\n";
				cin >> answer2;

				Studentas::write_file(answer2, Studentai);
			}
			else if (choiceOutput == 2) {

				cout << "\n" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)   Galutinis (Med.)" << "\n";
				cout << "----------------------------------------------------\n";
				for (int i = 0; i < Studentai.size(); i++) {
					cout << std::setw(15) << std::left << Studentai[i].pav << std::setw(15) << std::left << Studentai[i].vardas << std::setw(15) << std::left << std::fixed << std::setprecision(2) << Studentai[i].galutinisVid << "   " << std::fixed << std::setprecision(2) << Studentai[i].galutinisMed << "\n";
				}
				choiceOutput = 0;
			}

			//Iseiti is while loop
			choiceEndStud = 1;
		}

		//Perkeliam vieno studento duomenis
		Studentai.push_back(A);
		if (!Studentai.empty()) {
			//Apskaiciuojame vidurki ir galutini rezultata su juo kiekvienam studentui
			vidurkis = (double)suma / ((double)Studentai[m].paz.size());
			Studentai[m].galutinisVid = 0.4 * vidurkis + 0.6 * Studentai[m].egzaminas;
		}

		//Ivesti daugiau studentu choice
		if (choiceMenu != 4 && choiceMenu != 5) {
			m++; //Skaiciuojame studentu skaiciu / saugome indeksa
			do {
				input_validation(choiceEndStud, 0, 1, "\nAr vesite dar vieno studento duomenis? (0 - Taip, 1 - Ne, einame prie galutiniu rezultatu)\n");

			} while (choiceEndStud < 0 || choiceEndStud > 1);

			system("cls");
		}

		//Reset
		if (choiceMenu == 5) Studentai.clear();
		vidurkis = 0;
		suma = 0;
		n = 0;
	} while (choiceEndStud != 1);

	///GALUTINIS REZULTATAS
	if (!Studentai.empty()) {

		do {
			input_validation(choiceRez, 1, 2, "Kaip norite isvesti studentu galutinius rezultatus? (1 - Vidurkis, 2 - Mediana)\n");

		} while (choiceRez < 1 || choiceRez > 2);

		//VIDURKIS
		if (choiceRez == 1) {
			cout << "\nPavarde     Vardas         Galutinis(Vid.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << std::fixed << std::setprecision(2) << Studentai[i].galutinisVid << "\n\n";
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

				Studentai[i].galutinisMed = 0.4 * mediana + 0.6 * Studentai[i].egzaminas;
			}

			cout << "\nPavarde     Vardas         Galutinis(Med.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << std::fixed << std::setprecision(2) << Studentai[i].galutinisMed << "\n\n";
			}

			choiceRez = 0;
		}

		//Restart()
	}
	else if (Studentai.empty() && choiceMenu != 5) {
		cout << "Studentu duomenu nera.\n\n";
		//Restart();
	}

	return 0;
}
