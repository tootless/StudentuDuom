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


    return 0;
}