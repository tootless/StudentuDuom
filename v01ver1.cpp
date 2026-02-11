#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stdlib.h>

// Var. 1; Visi duomenu rinkiniai su C masyvais

using namespace std;

//Reiketu constructor, copy ir destructor nes dabar ypatingai nepatogu skaityti ir suprasti
struct Studentas {
	string vardas, pav;
	int pazKiekis = 0;
	int* paz = new int[2];
	int egzaminas = 0;
	double galutinis = 0; //Galutinis rezultatas
};

int main()
{
	int maxM = 2; //Pradinis maksimalus studentu skaicius
	int maxP = 2; //Pradinis maksimalus pazymiu skaicius;
	Studentas* Studentai = new Studentas[maxM]; //Galutiniai studentu duomenys
	int allN = 0; //Visu pazymiu skaicius; Naudojamas tvarkyti atminti
	int m = 0; //Studentu skaicius
	int suma = 0; //Pazymiu suma (Vidurkiui apskaiciuoti)
	double vidurkis = 0, mediana = 0;
	int choiceRez = 0; //Galutinio rez. isvedimo pasirinkimas
	int choiceEndStud = 0; //Studentu duomenu ivesties baigties pasirinkimas
	int choiceEndPaz = 0; //Pazymiu ivesties baigties pasirinkimas
	int choiceMenu = 0; //Pazymiu ivedimo / randomizavimo eigos pasirinkimas

	///DUOMENU IVESTIS
	do {
		if (m < maxM) {
			//change: do while vardas, pav, n, paz != exception || != null
			cout << "---STUDENTU DUOMENU IVEDIMAS---\n";

			cout << "Iveskite studento varda ir pavarde: \n";
			cout << "Vardas: ";
			cin >> Studentai[m].vardas;
			cout << "Pavarde: ";
			cin >> Studentai[m].pav;

			cout << "---PAZYMIU IVEDIMAS---\n";
			cout << "Pasirinkite pazymiu ivedimo buda " << m + 1 << "-am studentui "
				<< "\n(0 - Viskas ranka, 1 - Randomizuotas egz.balas, 2 - Randomizuoti nd pazymiai, 3 - Viskas randomizuota: ";
			cin >> choiceMenu;

			if (choiceMenu == 0) { //RANKA
				cout << "Iveskite studento egzamino bala: ";
				cin >> Studentai[m].egzaminas;

				cout << "Iveskite studento pazymius: \n";
				do {
					//Padidiname masyva
					if (allN == maxP - 1) {
						int newMaxPaz = maxP + 5; //Maksimalus pazymiu skaicius + 5
						int* newPaz = new int[newMaxPaz];

						copy(Studentai[m].paz, Studentai[m].paz + Studentai[m].pazKiekis, newPaz);
						delete[] Studentai[m].paz;


						Studentai[m].paz = newPaz;
						maxP = newMaxPaz;

						cout << "\n MAX PAZ SIZE INCREASED: " << maxP << endl; // DEBUG
					}
					//Ivedame pazymi
					int tempPaz = 0;
					cout << "Pazymys: ";
					cin >> tempPaz;
					Studentai[m].paz[Studentai[m].pazKiekis] = tempPaz;

					suma += tempPaz;

					Studentai[m].pazKiekis++; //Skaiciuojame atskiru studentu pazymiu kiekius; Tolimesniems skaiciavimams
					allN++; //Skaiciuoti visu pazymiu skaiciu

					cout << "\nCIA YRA ALLN \n" << allN << "\n";

					cout << "Ar vesite dar viena namu darbu pazymi? (0 - taip, 1 - ne, einame prie kito studento)\n";
					cin >> choiceEndPaz;

				} while (choiceEndPaz != 1);
			}
			if (choiceMenu == 1) {
				cout << "\n---RANDOMIZUOTI EGZAMINO BALAI---\n";

				srand(time(NULL));
				int tempEgzPazRnd = rand() % 10 + 1;
				Studentai[m].egzaminas = tempEgzPazRnd;
				cout << "Ivestas egzamino balas:\n";
				cout << "{ " << tempEgzPazRnd << " }\n";

				cout << "Iveskite studento pazymius: \n";
				do {
					//Padidiname masyva
					if (allN == maxP-1) { 
						int newMaxPaz = maxP + 5; //Maksimalus pazymiu skaicius + 5
						int* newPaz = new int[newMaxPaz];

						copy(Studentai[m].paz, Studentai[m].paz + Studentai[m].pazKiekis, newPaz);
						delete[] Studentai[m].paz;


						Studentai[m].paz = newPaz;
						maxP = newMaxPaz;

						cout << "\n MAX PAZ SIZE INCREASED: " << maxP << endl; // DEBUG
					}
					//Ivedame pazymi
					int tempPaz = 0;
					cout << "Pazymys: ";
					cin >> tempPaz;
					Studentai[m].paz[Studentai[m].pazKiekis] = tempPaz;

					suma += tempPaz;

					Studentai[m].pazKiekis++; //Skaiciuojame atskiru studentu pazymiu kiekius; Tolimesniems skaiciavimams
					allN++; //Skaiciuoti visu pazymiu skaiciu

					cout << "\nCIA YRA ALLN \n" << allN << "\n";


					cout << "Ar vesite dar viena namu darbu pazymi? (0 - taip, 1 - ne, einame prie kito studento)\n";
					cin >> choiceEndPaz;

				} while (choiceEndPaz != 1);
			}

			if (choiceMenu == 2) {
				cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n";

				cout << "Iveskite studento egzamino bala: \n";
				cin >> Studentai[m].egzaminas;

				srand(time(NULL));
				cout << "Iveskite namu darbu pazymiu skaiciu:";
				cin >> Studentai[m].pazKiekis;

				allN += Studentai[m].pazKiekis;

				if (Studentai[m].pazKiekis >= maxP) {
					int newMaxPaz = maxP + Studentai[m].pazKiekis + 5; //Maksimalus pazymiu skaicius + ivestas sk + 5
					int* newPaz = new int[newMaxPaz];

					copy(Studentai[m].paz, Studentai[m].paz + Studentai[m].pazKiekis, newPaz);
					delete[] Studentai[m].paz;


					Studentai[m].paz = newPaz;
					maxP = newMaxPaz;

					cout << "\n MAX PAZ SIZE INCREASED: " << maxP << endl; // DEBUG
				}
				for (int i = 0; i < Studentai[m].pazKiekis; i++) {
					int tempPazRnd = rand() % 10 + 1;
					Studentai[m].paz[i] = tempPazRnd;

					suma += tempPazRnd;
				}

				cout << "Ivesti pazymiai:\n{ ";
				for (int i = 0; i < Studentai[m].pazKiekis; i++) {
					cout << Studentai[m].paz[i] << " ";
				}
				cout << " }";
			}

			if (choiceMenu == 3) {
				cout << "\n---RANDOMIZUOTI EGZAMINO BALAI BEI NAMU DARBU PAZYMIAI---\n";

				srand(time(NULL));
				int tempEgzPazRnd = rand() % 10 + 1;
				Studentai[m].egzaminas = tempEgzPazRnd;
				cout << "Ivestas egzamino balas:\n";
				cout << "{ " << tempEgzPazRnd << " }\n";

				srand(time(NULL));
				cout << "Iveskite namu darbu pazymiu skaiciu:";
				cin >> Studentai[m].pazKiekis;

				allN += Studentai[m].pazKiekis;

				if (Studentai[m].pazKiekis >= maxP) {
					int newMaxPaz = maxP + Studentai[m].pazKiekis + 5; //Maksimalus pazymiu skaicius + ivestas sk + 5
					int* newPaz = new int[newMaxPaz];

					copy(Studentai[m].paz, Studentai[m].paz + Studentai[m].pazKiekis, newPaz);
					delete[] Studentai[m].paz;


					Studentai[m].paz = newPaz;
					maxP = newMaxPaz;

					cout << "\n MAX PAZ SIZE INCREASED: " << maxP << endl; // DEBUG
				}
				for (int i = 0; i < Studentai[m].pazKiekis; i++) {
					int tempPazRnd = rand() % 10 + 1;
					Studentai[m].paz[i] = tempPazRnd;

					suma += tempPazRnd;
				}

				cout << "Ivesti pazymiai:\n{ ";
				for (int i = 0; i < Studentai[m].pazKiekis; i++) {
					cout << Studentai[m].paz[i] << " ";
				}
				cout << " }";
			}

			//Apskaiciuojame vidurki ir galutini rezultata kiekvienam studentui (kaip placeholder)
			vidurkis = (double)suma / (double)Studentai[m].pazKiekis;
			Studentai[m].galutinis = 0.4 * vidurkis + 0.6 * Studentai[m].egzaminas;

			m++; //Skaiciuojame studentu skaiciu / saugome indeksa
			//Reset
			vidurkis = 0;
			suma = 0;
		}
		else if (m == maxM) {
			//Sukuriame nauja (didesni) Studentai masyva
			int newMaxM = maxM * 2; //Maksimalus studentu skaicius * 2
			Studentas* NewStudentai = new Studentas[newMaxM];

			copy(Studentai, Studentai + m, NewStudentai);

			delete[] Studentai;

			Studentai = NewStudentai;
			maxM = newMaxM;

			cout << "\nMAX STUDENT COUNT INCREASED: " << maxM;

			continue;
		}

		cout << "Ar vesite dar vieno studento duomenis? (0 - taip, 1 - ne, einame prie galutiniu rezultatu)\n";
		cin >> choiceEndStud;

		system("cls");

	} while (choiceEndStud != 1);

	///GALUTINIS REZULTATAS
	cout << "Kaip norite isvesti studentu galutinius rezultatus? (1 - Vidurkis, 2 - Mediana)\n";
	cin >> choiceRez;

	for (int i = 0; i < m; i++) {

		cout << "\n\n\nDEBUG Studentas " << i << ": ";
		cout << "pazKiekis = " << Studentai[i].pazKiekis;
		cout << ", pazymiai: ";
		for (int j = 0; j < Studentai[i].pazKiekis; j++) {
			cout << Studentai[i].paz[j] << " ";
		}
		cout << endl << endl;

		if (choiceRez == 1) { //Vidurkis
			cout << "\nPavarde     Vardas         Galutinis(Vid.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << fixed << setprecision(2) << Studentai[i].galutinis << endl;
			}

			choiceRez = 0;
		}
		else if (choiceRez == 2) { //Mediana
			//Rasti mediana
			sort(Studentai[i].paz, Studentai[i].paz + Studentai[i].pazKiekis);

			if (Studentai[i].pazKiekis % 2 == 0) {
				int midLeftElem = Studentai[i].pazKiekis / 2 - 1;
				mediana = (Studentai[i].paz[midLeftElem] + Studentai[i].paz[Studentai[i].pazKiekis / 2]) / 2;
			}
			else {
				mediana = Studentai[i].paz[Studentai[i].pazKiekis / 2];
			}

			Studentai[i].galutinis = 0.4 * mediana + 0.6 * Studentai[i].egzaminas;

			cout << "\nPavarde     Vardas         Galutinis(Med.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < m; i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << fixed << setprecision(2) << Studentai[i].galutinis << endl;
			}

			choiceRez = 0;
		}
	}

	return 0;
}