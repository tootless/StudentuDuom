#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <stdlib.h>

// Var. 2; Visi duomenu rinkiniai su std::vector

using namespace std;

struct Studentas {
	string vardas, pav;
	vector<int> paz;
	int egzaminas = 0;
	double galutinis = 0; //Galutinis rezultatas
};

int main()
{
	Studentas A; //Temp studentas su realiais duomenimis
	vector<Studentas> Studentai; //Galutiniai studentu duomenys
	int n = 0; //Pazymiu skaicius
	int m = 0; //Studentu skaicius
	int suma = 0; //Pazymiu suma (Vidurkiui apskaiciuoti)
	double vidurkis = 0, mediana = 0;
	int choiceRez = 0; //Galutinio rez. isvedimo pasirinkimas
	int choiceEndStud = 0; //Studentu (struct) duomenu ivesties baigties pasirinkimas
	int choiceEndPaz = 0; //Pazymiu ivesties baigties pasirinkimas
	int choiceRand = 0; //Pazymiu ivedimo / randomizavimo eigos pasirinkimas
	///DUOMENU IVESTIS

	do {
		//change: do while vardas, pav, n, paz != exception || != null
		cout << "---STUDENTU DUOMENU IVEDIMAS---\n";

		cout << "Iveskite studento varda: \n";
		cout << "Vardas: ";
		cin >> A.vardas;
		cout << "Iveskite studento pavarde: \n";
		cout << "Pavarde: ";
		cin >> A.pav;

		cout << "---PAZYMIU IVEDIMAS---\n";
		cout << "Pasirinkite pazymiu ivedimo buda " << m+1 << "-am studentui "
			<< "\n(0 - Viskas ranka, 1 - Randomizuotas egz.balas, 2 - Randomizuoti nd pazymiai, 3 - Viskas randomizuota: ";
		cin >> choiceRand;

		if (choiceRand == 0) { //RANKA
			cout << "Iveskite studento egzamino bala: \n";
			cin >> A.egzaminas;

			cout << "Iveskite studento pazymius:\n";
			do {
				n++; //Skaiciuoti pazymiu skaiciu
				int tempPaz;
				cout << "Pazymys: ";
				cin >> tempPaz;
				A.paz.push_back(tempPaz);
				cout << "\n";

				suma += tempPaz;

				cout << "Ar vesite dar viena namu darbu pazymi? (0 - Taip, 1 - Ne, einame prie kito studento)\n";
				cin >> choiceEndPaz;
			} while (choiceEndPaz != 1);
		}
		//Reiketu ivesti funkcijas
		else if (choiceRand == 1) { //RND EGZAMINAS
			cout << "\n---RANDOMIZUOTI EGZAMINO BALAI---\n";

			srand(time(NULL));
			int tempEgzPazRnd = rand() % 10 + 1;
			A.egzaminas = tempEgzPazRnd;
			cout << "Ivestas egzamino balas:\n";
			cout << "{ " << tempEgzPazRnd << " }\n";

			cout << "Iveskite studento pazymius:\n";
			do {
				n++; //Skaiciuoti pazymiu skaiciu
				int tempPaz;
				cout << "Pazymys: ";
				cin >> tempPaz;
				A.paz.push_back(tempPaz);
				cout << "\n";

				suma += tempPaz;

				cout << "Ar vesite dar viena namu darbu pazymi? (0 - Taip, 1 - Ne, einame prie kito studento)\n";
				cin >> choiceEndPaz;
			} while (choiceEndPaz != 1);
		}

		else if (choiceRand == 2) { //RND ND
			cout << "\n---RANDOMIZUOTI NAMU DARBU PAZYMIAI---\n";

			cout << "Iveskite studento egzamino bala: \n";
			cin >> A.egzaminas;
			
			cout << "Iveskite namu darbu pazymiu skaiciu:";
			cin >> n;

			srand(time(NULL));
			for (int i = 0; i < n; i++) {
				int tempPazRnd = rand() % 10 + 1;
				A.paz.push_back(tempPazRnd);

				suma += tempPazRnd;
			}

			cout << "Ivesti pazymiai:\n{ ";
			for (int i = 0; i < n; i++) {
				cout << A.paz[i] << " ";
			}
			cout << " }";
		}

		else if (choiceRand == 3) { //RND VISKAS
			cout << "\n---RANDOMIZUOTI EGZAMINO BALAI BEI NAMU DARBU PAZYMIAI---\n";

			srand(time(NULL));
			int tempEgzPazRnd = rand() % 10 + 1;
			A.egzaminas = tempEgzPazRnd;
			cout << "Ivestas egzamino balas:\n";
			cout << "{ " << tempEgzPazRnd << " }\n";

			cout << "Iveskite namu darbu pazymiu skaiciu:\n";
			cin >> n;

			srand(time(NULL));
			for (int i = 0; i < n; i++) {
				int tempPazRnd = rand() % 10 + 1;
				A.paz.push_back(tempPazRnd);

				suma += tempPazRnd;
			}

			cout << "Ivesti pazymiai:\n { ";
			for (int i = 0; i < n; i++) {
				cout << A.paz[i] << " ";
			}
			cout << " }";
		}
		Studentai.push_back(A);

		vidurkis = suma / (double)n; //Suskaiciuoti vidurki
		Studentai[m].galutinis = 0.4 * vidurkis + 0.6 * Studentai[m].egzaminas; //Apskaiciuoti galutini rezultata su vidurkiu

		m++; //Skaiciuojame studentu skaiciu / saugome indeksa

		cout << "Ar vesite dar vieno studento duomenis? (0 - Taip, 1 - Ne, einame prie galutiniu rezultatu)\n";
		cin >> choiceEndStud;
		//Reset
		system("cls");
		vidurkis = 0;
		suma = 0;
		n = 0;

	} while (choiceEndStud != 1);

	///GALUTINIS REZULTATAS
	cout << "Kaip norite isvesti studentu galutinius rezultatus? (1 - Vidurkis, 2 - Mediana)\n";
	cin >> choiceRez;

	for (int i = 0; i < Studentai.size(); i++) {
		if (choiceRez == 1) {
			cout << "\nPavarde     Vardas         Galutinis(Vid.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < Studentai.size(); i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << fixed << setprecision(2) << Studentai[i].galutinis << endl;
			}
			choiceRez = 0;
		}
		else if (choiceRez == 2) {
			//Rasti mediana
			n = Studentai[i].paz.size();
			sort(Studentai[i].paz.begin(), Studentai[i].paz.end());
			if (n % 2 == 0) {
				int midLeftElem = n / 2 - 1;
				mediana = (Studentai[i].paz[midLeftElem] + Studentai[i].paz[n / 2]) / 2;
			}
			else
				mediana = Studentai[i].paz[n / 2];


			Studentai[i].galutinis = 0.4 * mediana + 0.6 * Studentai[i].egzaminas;

			cout << "\nPavarde     Vardas         Galutinis(Med.)\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < Studentai.size(); i++) {
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << fixed << setprecision(2) << Studentai[i].galutinis << endl;
			}

			choiceRez = 0;
		}
	}

	return 0;
}