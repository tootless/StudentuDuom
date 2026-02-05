#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

// Var. 2; Visi duomenu rinkiniai su std::vector

using namespace std;

struct Studentas {
    string vardas, pav;
    vector<int> paz;
    int egzaminas;
    double galutinis; //Galutinis rezultatas
};

int main()
{
    Studentas A;
    int n; //Pazymiu skaicius
    int suma = 0; //Pazymiu suma (Vidurkiui apskaiciuoti)
    int choiceRez = 0; //Galutinio rez. isvedimo pasirinkimas
    int choiceEnd = 0; //Programos baigties pasirinkimas;
    double vidurkis = 0, mediana = 0;

    //change: do while choiceEnd != 0
    cout << "Iveskite studento varda ir pavarde: \n";
    cout << "Vardas: ";
    //change: do while vardas, pav, n, paz != exception || != null
    cin >> A.vardas;
    cout << "Pavarde: ";
    cin >> A.pav;

    cout << "Iveskite studento pazymiu skaiciu: ";
    cin >> n;

    cout << "Iveskite studento pazymius: \n";
    for (int i = 0; i < n; i++) {
        int tempPaz;
        cout << "Pazymys: ";
        cin >> tempPaz;
        A.paz.push_back(tempPaz);
        cout << "\n";

        suma += temp;
    }
    cout << "Iveskite studento egzamino bala: ";
    cin >> A.egzaminas;

    //console.clear()???
    //change: do while choiceRez != 1 || choiceRez != 2
    cout << "\nKaip norite isvesti galutini rezultata?\n 1 - Vidurkis, 2 - Mediana\n";
    cin >> choiceRez;
    if (choiceRez == 1) {
        vidurkis = suma / (double)n; //Suskaiciuojamas vidurkis
        A.galutinis = 0.4 * vidurkis + 0.6 * A.egzaminas;

        cout << "Pavarde     Vardas         Galutinis(Vid.)\n";
        cout << "------------------------------------------\n";
        cout << A.pav << "           " << A.vardas << "              " << setprecision(2) << A.galutinis;
    }
    else if (choiceRez == 2) {
        sort(A.paz.begin(), A.paz.end());
        //Patikrinti medianos radimo buda
        if (n % 2 == 0) {
            int midLeftElem = n / 2 - 1;
            mediana = (A.paz[midLeftElem] + A.paz[n / 2]) / 2;
        }
        else {
            mediana = A.paz[n / 2];
        }
        A.galutinis = 0.4 * mediana + 0.6 * A.egzaminas;

        cout << "Pavarde     Vardas         Galutinis(Med.)\n";
        cout << "------------------------------------------\n";
        cout << A.pav << "           " << A.vardas << "              " << setprecision(2) << A.galutinis;
    }
    else {
        cout << "neveikia";
    }
    return 0;
}