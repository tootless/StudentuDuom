#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
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
	int choiceRez = 0; //Galutinio rez. isvedimo pasirinkimas
	int choiceEndStud = 0; //Studentu (struct) duomenu ivesties baigties pasirinkimas
	int choiceEndPaz = 0; //Pazymiu ivesties baigties pasirinkimas
	double vidurkis = 0, mediana = 0;

	///DUOMENU IVESTIS

	do {
		//change: do while vardas, pav, n, paz != exception || != null
		cout << "Iveskite studento varda ir pavarde: \n";
		cout << "Vardas: ";
		cin >> A.vardas;
		cout << "Pavarde: ";
		cin >> A.pav;

		cout << "Iveskite studento egzamino bala: ";
		cin >> A.egzaminas;

		cout << "Iveskite studento pazymius: \n";
		do {
			n++; //Skaiciuoti pazymiu skaiciu
			int tempPaz;
			cout << "Pazymys: ";
			cin >> tempPaz;
			A.paz.push_back(tempPaz);
			cout << "\n";

			suma += tempPaz;

			cout << "Ar vesite dar viena namu darbu pazymi? (0 - taip, 1 - ne, einame prie kito studento)\n";
			cin >> choiceEndPaz;
		} while (choiceEndPaz != 1);

		Studentai.push_back(A);

		vidurkis = suma / (double)n; //Suskaiciuoti vidurki
		Studentai[m].galutinis = 0.4 * vidurkis + 0.6 * Studentai[m].egzaminas; //Apskaiciuoti galutini rezultata su vidurkiu

		m++; //Skaiciuojame studentu skaiciu / saugome indeksa

		cout << "Ar vesite dar vieno studento duomenis? (0 - taip, 1 - ne, einame prie galutiniu rezultatu)\n";
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
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << setprecision(2) << Studentai[i].galutinis << endl;
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
				cout << Studentai[i].pav << "           " << Studentai[i].vardas << "              " << setprecision(2) << Studentai[i].galutinis << endl;
			}

			choiceRez = 0;
		}
	}

	return 0;
}