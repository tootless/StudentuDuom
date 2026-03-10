#include "mylib.h"
#include "functions.h"
#include "timer.h"

//Visi duomenu rinkiniai su std::vector

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

	file_generator(1000, 15);
	file_generator(10000, 15);
	file_generator(100000, 15);
	file_generator(1000000, 15);
	file_generator(10000000, 15);


	do {

		//MENIU
		do {
			menu();

			number_input_validation(choiceMenu, 1, 5);

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
				number_input_validation(n, 1, -1, "Iveskite norima namu darbu pazymiu skaiciu:\n");

			} while (n < 1);

			A.rand_paz(n, suma);
		}

		//RND VISKAS
		else if (choiceMenu == 3) {
			cout << "\n---RANDOMIZUOTAS STUDENTO VARDAS IR PAVARDE";
			A.rand_varpav();

			cout << "\n---RANDOMIZUOTAS EGZAMINO BALAS---\n\n";

			A.rand_egz();

			cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n\n";

			do {
				number_input_validation(n, 1, -1, "Iveskite norima namu darbu pazymiu skaiciu:");

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
			std::string filename_input;
			int choiceOutput, choiceSort;
			cout << "\n---STUDENTO DUOMENU NUSKAITYMAS IS FAILO---\n\n";

			//Skaitymas
			bool read_success = true;
			do {
				cout << "\nIveskite failo pavadinima, is kurio norite nuskaityti:\n";
				getline(cin, filename_input);

				//Start timer
				//Timer timer;

				Studentai = Studentas::read_file(filename_input, suma);
				if (Studentai.empty()) {
					read_success = 1;
				}
				else {
					//cout << "\n\n FAILA PERSKAITYTI UZTRUKO: " << timer.elapsed() << " s\n\n";
					read_success = 0;
				}
			} while (read_success == 1);

			cout << "\n---STUDENTO DUOMENU ISANKSTINIS SURUSIAVIMAS/ISRIKIAVIMAS---\n\n";

			//Rūšiavimas
			do {
				number_input_validation(choiceSort, 1, 4, "\nKaip norite surusiuoti studentus? \n1 - Pagal vardus,\n2 - Pagal pavardes,\n3 - Pagal galutini (vid.),\n4- Pagal galutini (med.)\n");

			} while (choiceSort < 1 || choiceSort > 4);

			sort(Studentai.begin(), Studentai.end(),
				[choiceSort](const Studentas& a, const Studentas& b) -> bool {
					if (choiceSort == 1) {
						if (a.vardas != b.vardas) return a.vardas < b.vardas;
					}
					else if (choiceSort == 2) {
						if (a.pav != b.pav) return a.pav < b.pav;
					}
					else if (choiceSort == 3) {
						return a.galutinisVid > b.galutinisVid;
					}
					else {
						return a.galutinisMed > b.galutinisMed;
					}
				});

			//Isvedimas
			do {
				number_input_validation(choiceOutput, 1, 2, "\nKur norite isvesti studentu galutinius rezultatus? (1 - Faile, 2 - Ekrane)\n");

			} while (choiceOutput < 1 || choiceOutput > 2);

			if (choiceOutput == 1) {
				std::string answer2;
				cout << "\nIveskite failo pavadinima, i kuri norite irasyti duomenis (arba sukurti nauja, jeigu failo su tokiu pav. nera):\n";
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
		if (choiceMenu != 5) Studentai.push_back(A);
		if (!Studentai.empty()) {
			//Apskaiciuojame galutini rezultata kiekvienam studentui
			vidurkis = (double)suma / ((double)Studentai[m].paz.size());
			Studentai[m].galutinisVid = 0.4 * vidurkis + 0.6 * Studentai[m].egzaminas;

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
		}

		//Testi studentu duom ivedima
		if (choiceMenu != 4 && choiceMenu != 5) {
			m++; //Skaiciuojame studentu skaiciu / saugome indeksa
			do {
				number_input_validation(choiceEndStud, 0, 1, "\nAr vesite dar vieno studento duomenis? (0 - Taip, 1 - Ne, einame prie galutiniu rezultatu)\n");

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
			number_input_validation(choiceRez, 1, 2, "Kaip norite isvesti studentu galutinius rezultatus? (1 - Vidurkis, 2 - Mediana)\n");

		} while (choiceRez < 1 || choiceRez > 2);

		system("cls");

		//VIDURKIS
		if (choiceRez == 1) {
			//Rūšiavimas
			int choiceSort;
			do {
				number_input_validation(choiceSort, 1, 3, "Kaip norite surūšiuoti studentus? \n1 - Pagal vardus,\n2 - Pagal pavardes,\n3 - Pagal galutini (vid.)\n");

			} while (choiceSort < 1 || choiceSort > 3);

			sort(Studentai.begin(), Studentai.end(),
				[choiceSort](const Studentas& a, const Studentas& b) -> bool {
					if (choiceSort == 1) {
						if (a.vardas != b.vardas) return a.vardas < b.vardas;
					}
					else if (choiceSort == 2) {
						if (a.pav != b.pav) return a.pav < b.pav;
					}
					else if (choiceSort == 3) {
						return a.galutinisVid > b.galutinisVid;
					}
					else {
						return a.galutinisMed > b.galutinisMed;
					}
				});

			cout << "\n" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)" << "\n";
			cout << "----------------------------------------------------\n";
			for (int i = 0; i < Studentai.size(); i++) {
				cout << std::setw(15) << std::left << Studentai[i].pav << std::setw(15) << std::left << Studentai[i].vardas << std::setw(15) << std::left << std::fixed << std::setprecision(2) << Studentai[i].galutinisVid << "   " << "\n";
			}
			choiceRez = 0;
		}
		//MEDIANA
		else if (choiceRez == 2) {
			//Rūšiavimas
			int choiceSort;
			do {
				number_input_validation(choiceSort, 1, 3, "Kaip norite surūšiuoti studentus? \n1 - Pagal vardus,\n2 - Pagal pavardes,\n3 - Pagal galutini (vid.),\n4- Pagal galutini (med.)\n");

			} while (choiceSort < 1 || choiceSort > 3);

			sort(Studentai.begin(), Studentai.end(),
				[choiceSort](const Studentas& a, const Studentas& b) -> bool {
					if (choiceSort == 1) {
						if (a.vardas != b.vardas) return a.vardas < b.vardas;
					}
					else if (choiceSort == 2) {
						if (a.pav != b.pav) return a.pav < b.pav;
					}
					else if (choiceSort == 3) {
						return a.galutinisVid > b.galutinisVid;
					}
					else {
						return a.galutinisMed > b.galutinisMed;
					}
				});


			cout << "\nPavarde     Vardas         Galutinis(Med.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << std::setw(15) << std::left << Studentai[i].pav << std::setw(15) << std::left << Studentai[i].vardas << std::setw(15) << std::left << std::fixed << std::setprecision(2) << Studentai[i].galutinisMed << "   " << "\n";
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
