//function implementations file

#include "functions.h"


//STRUCT STUDENTAS FUNKCIJOS
//DARBAS SU FAILU
//
std::vector<Studentas> Studentas::read_file(const std::string filename, int& suma) {

	std::vector<Studentas> tempStudentai;

	fs::path filePath = filename;

	try {
		//CHECK IMPORTANT EXCEPTIONS

		if (filePath.extension() != ".txt") {
			throw std::runtime_error("\n---KLAIDA: Failas " + filename + " turi baigtis '.txt'---\n");
		}

		if (!fs::exists(filename)) {
			throw std::runtime_error("\n---KLAIDA: Failas " + filename + " neegzistuoja---\n");
		}

		//Open file
		std::fstream fin(filename, std::ios::in);

		if (!fin.is_open()) {
			throw std::runtime_error("\n---KLAIDA: Failo " + filename + " nepavyko atidaryti---\n");
		}

		if (fs::file_size(filename) == 0) {
			throw std::runtime_error("\n---KLAIDA: Failas " + filename + " yra tuscias---\n");
		}

		//Read file
		std::string curr_eil; //current eilute

		fin.ignore(INT32_MAX, '\n');

		while (std::getline(fin, curr_eil)) {
			Studentas A; //temp Studentas
			int tempPaz;

			std::istringstream iss(curr_eil);
			iss >> A.vardas >> A.pav;

			//read visus pazymius
			while (iss >> tempPaz) {
				A.paz.push_back(tempPaz);
				suma += tempPaz;
			}
			//paskutinis pazymys paz vector yra egzamino balas
			A.egzaminas = A.paz.back();
			A.paz.pop_back();

			//apskaiciuoti galutinius rezultatus, kadangi isvedami abu
			double vidurkis = (double)suma / (double)A.paz.size();
			A.galutinisVid = 0.4 * vidurkis + 0.6 * A.egzaminas;

			int a = A.paz.size();
			double mediana;
			sort(A.paz.begin(), A.paz.end());
			if (a % 2 == 0) {
				int midLeftElem = a / 2 - 1;
				mediana = (A.paz[midLeftElem] + A.paz[a / 2]) / 2;
			}
			else
				mediana = A.paz[a / 2];

			A.galutinisMed = 0.4 * mediana + 0.6 * A.egzaminas;



			tempStudentai.push_back(A);

			suma = 0;
		}

		fin.close();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";

		return tempStudentai; //Empty
	}

	return tempStudentai;
}

void Studentas::write_file(const std::string filename, const std::vector<Studentas>& Studentai) {
	std::ofstream fout(filename);

	fout << "\n" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)   Galutinis (Med.)" << "\n";
	fout << "----------------------------------------------------\n";
	for (const auto& s : Studentai) {
		fout << std::setw(15) << std::left << s.pav << std::setw(15) << std::left << s.vardas << std::setw(15) << std::left << std::fixed << std::setprecision(2) << s.galutinisVid << "   " << std::fixed << std::setprecision(2) << s.galutinisMed << "\n";
	}


}

//DARBAS SU EKRANU
// 
//Vardo, pavardes ivestis
void Studentas::varpav_input()
{
	string_input_validation(vardas, "Iveskite studento varda:\nVardas: ");

	string_input_validation(pav, "Iveskite studento pavarde:\nPavarde: ");
	cout << "\n";
}

//Nd pazymiu ivestis
void Studentas::paz_input(int& suma)
{
	cout << "Iveskite studento pazymius:\n";

	int tempPaz;
	int choiceEndPaz = 0;

	do {
		number_input_validation(tempPaz, 1, 10, "Pazymys:\n");

		suma += tempPaz;
		paz.push_back(tempPaz);

		do {
			number_input_validation(choiceEndPaz, 0, 1, "\nAr vesite dar viena pazymi? (0 - Taip, 1 - Ne, eikime prie kito studento):\n");

		} while (choiceEndPaz < 0 || choiceEndPaz > 1);
	} while (choiceEndPaz != 1);
}

//Egzamino balo ivestis
void Studentas::egz_input()
{
	number_input_validation(egzaminas, 1, 10, "Iveskite studento egzamino bala:\n");
}

//Randomizuoti nd pazymiai
void Studentas::rand_paz(int& pazSk, int& suma) //pazSk -> vartotojo ivestas pazymiu kiekis
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
void Studentas::rand_egz()
{
	int tempEgzPazRnd = rand() % 10 + 1;
	egzaminas = tempEgzPazRnd;
	cout << "Ivestas egzamino balas:\n";
	cout << "{ " << tempEgzPazRnd << " }\n";
}

//Randomizuotas vardas ir pavarde
void Studentas::rand_varpav()
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

//GLOBALIOS FUNKCIJOS
void menu() {
	cout << "\nMENIU\n";
	cout << "\n--------\n";
	cout << "Pasirinkite programos eiga\n\n"
		<< "1 - Viskas ranka,\n2 - Randomizuoti nd. pazymiai ir egz. balas,\n3 - Viskas randomizuota,\n4 - Baigti darba (Ir isvesti galutinius rezultatus),\n5 - Skaityti visus duomenis is failo.";
	cout << "\n--------\n";
}

void number_input_validation(int& choice, int lowEnd, int highEnd, std::string optionalPrompt) { //if highEnd = -1, no highEnd used
	std::string input;

	while (true) {
		try {
			cout << optionalPrompt;
			getline(cin, input);

			if (input.empty()) {
				throw std::runtime_error("\n---KLAIDA: Ivestis tuscia---\n");
			}

			bool isNumber = true;
			for (auto i : input) {
				if (!isdigit(i)) {
					isNumber = false;
					break;
				}
			}

			if (!isNumber) {
				throw std::runtime_error("\n---KLAIDA: Iveskite realuji skaiciu---\n");
			}

			//string to int
			choice = stoi(input);

			//check range
			if (choice < lowEnd || (choice > highEnd && highEnd != -1)) {
				std::string errorMsg = "\n---KLAIDA: Iveskite realuji skaiciu";
				if (highEnd != -1) {
					errorMsg += " nuo " + std::to_string(lowEnd) + " iki " + std::to_string(highEnd) + "---\n";
				}
				else {
					errorMsg += " nuo " + std::to_string(lowEnd) + "---\n";
				}
				throw std::out_of_range(errorMsg);
			}

			//valid input
			break;
		}
		catch (const std::exception& e) {
			std::cerr << e.what();
		}
	}
}

void string_input_validation(std::string& input, std::string optionalPrompt) {
	while (true) {
		try {
			cout << optionalPrompt;
			getline(cin, input);

			if (input.empty()) {
				throw std::runtime_error("\n---KLAIDA: Ivestis tuscia---\n");
			}

			//check if string valid
			bool isLetter = true;
			for (auto i : input) {
				if (!isalpha(i) || i == ' ') {
					isLetter = false;

					break; //if any not letter, stop checking
				}
			}

			if (isLetter == false) {
				throw std::runtime_error("\n---KLAIDA: Iveskite tik raides---\n");
			}
			//valid input
			break;
		}
		catch (const std::exception& e) {
			std::cerr << e.what();
		}
	}
}

void file_generator(int nStud, int nPaz) { //nStud A.K.A. number of entries

	//try catch if file exists
	
	//create file name automatically
	std::string filename = "studentai";
	std::string fileend = ".txt";
	std::string nStudents = std::to_string(nStud);

	filename.append(nStudents);
	filename.append(fileend);

	std::ofstream fout(filename);

	//file header
	std::string nd = "ND";

	fout << std::setw(24) << std::left << "Vardas" << std::setw(27) << std::left << "Pavarde";

	for (int i = 0; i < nPaz; i++) {
		fout << std::setw(10) << std::left << nd.append(std::to_string(i+1));
		nd = "ND";
	}
	fout << std::left << "Egz.\n";

	//file entries (stud data)
	std::string studVar = "Vardas";
	std::string studPav = "Pavarde";
	int pazRnd;


	for (int i = 0; i < nStud; i++) {

		//name
		fout << std::setw(24) << std::left << studVar.append(std::to_string(i+1));
		//last name
		fout << std::setw(27) << std::left << studPav.append(std::to_string(i+1));

		//paz
		for (int i = 0; i < nPaz; i++) {
			pazRnd = rand() % 10 + 1;
			fout << std::right << pazRnd << std::setw(10);
		}

		//egz
		pazRnd = rand() % 10 + 1;
		fout << std::right << pazRnd;

		studVar = "Vardas";
		studPav = "Pavarde";

		if (i+1 != nStud) fout << "\n"; //paskutinis entry neturetu sukurti dar vienos \n
	}


}

void file_split(std::string& filename) {
	//filename input prompt + filename validation;

	//read file
	std::vector <Studentas> studentai;
	int suma = 0;

	studentai = Studentas::read_file(filename, suma); //galutinisVid calculated here

	//sort by choice
	int choiceSort;
	do {
		number_input_validation(choiceSort, 1, 4, "\nKaip norite surusiuoti studentus? \n1 - Pagal vardus,\n2 - Pagal pavardes,\n3 - Pagal galutini (vid.),\n4- Pagal galutini (med.)\n");

	} while (choiceSort < 1 || choiceSort > 4);

	sort(studentai.begin(), studentai.end(),
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

	//construct two new filenames
	std::string fileGood, fileBad; //galutinisVid >= 5.0; galutinisVid < 5.0

	filename.erase(filename.end()-4, filename.end()); //remove .txt to make new filenames
	fileGood = filename; fileBad = filename;

	fileGood.append("geri.txt"); fileBad.append("nepazangus.txt");
	
	//
	
}