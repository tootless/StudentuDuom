//Global functions

#include "mylib.h"
#include <iostream>

using std::cout;
using std::cin;

void menu(int& m) {
	cout << "\nMENIU\n";
	cout << "\n--------\n";
	cout << "Pasirinkite programos eiga " << m + 1 << "-am studentui:\n\n"
		<< "1 - Viskas ranka,\n2 - Randomizuoti nd. pazymiai ir egz. balas,\n3 - Viskas randomizuota,\n4 - Baigti darba (Ir isvesti galutinius rezultatus).";
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