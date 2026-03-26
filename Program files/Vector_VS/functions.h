//function declarations file

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout;
using std::cin;

struct Studentas {
	std::string vardas, pav;
    std::vector<int> paz;
    int egzaminas = 0;
    double galutinisVid = 0;
    double galutinisMed = 0;

    void varpav_input();
    void paz_input(int& suma);
    void egz_input();
    void rand_paz(int& suma);
    void rand_egz();
    void rand_varpav();
};

std::vector<Studentas> read_file(std::string& filename, int& suma);

//Perskaityti egzistuojanti studentu duomenu faila
template<typename StudentaiContainer>
StudentaiContainer read_file_testing(std::string& filename, int& suma) {

	StudentaiContainer tempStudentai;

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

//Irasyti studentu duomenis i faila / sukurti nauja faila su duomenimis
template<typename StudentaiContainer>
void write_studentai(const std::string filename, StudentaiContainer& studentai) {
	//sorting
	//int choiceOutput;



	//write to file
	std::ofstream fout(filename);

	fout << "\n" << std::setw(15) << std::left << "Pavarde" << std::setw(15) << std::left << "Vardas" << std::setw(15) << std::left << "Galutinis (Vid.)   Galutinis (Med.)" << "\n";
	fout << "----------------------------------------------------\n";
	for (const auto& s : studentai) {
		fout << std::setw(15) << std::left << s.pav << std::setw(15) << std::left << s.vardas << std::setw(15) << std::left << std::fixed << std::setprecision(2) << s.galutinisVid << "   " << std::fixed << std::setprecision(2) << s.galutinisMed << "\n";
	}

	fout.close();
}

void student_file_generator(int nStud, int nPaz);

void split_file_generator(std::string& filename, std::vector<Studentas>& studentai);

void student_split(std::string filename, std::vector<Studentas>& studentai);

template <typename StudentaiContainer>
void student_split_testing(std::string filename, StudentaiContainer& studentai) {
	//sort by galutinisVid
	student_sort_testing(studentai);

	//move students to new vectors
	StudentaiContainer studGeri, studBlogi;

	for (auto& s : studentai) {
		if (s.galutinisVid < 5.0) {
			studBlogi.push_back(std::move(s));
		}
		else
			studGeri.push_back(std::move(s));
	}
	studentai.clear();
}

void menu(int& choiceMenu);

void number_input_validation(int& choice, int lowEnd, int highEnd, std::string optionalPrompt = "");

void string_input_validation(std::string& input, std::string optionalPrompt = "");

void student_sort(std::vector<Studentas>& studentai);

//Studentu vektoriaus rusiavimas didejimo tvarka pagal galutiniVid
template<typename StudentaiContainer>
void student_sort_testing(StudentaiContainer& studentai) {
	sort(studentai.begin(), studentai.end(),
		[](const Studentas& a, const Studentas& b) -> bool {
			return a.galutinisVid < b.galutinisVid;
		});
}

void calculate_galutinis();

//void test1_files
void testing_v04_1(int nStud);

//void test2_files
void testing_v04_2(std::vector<Studentas>& studentai, const std::string filename, int& suma);

//void do_test_files

//Initial test of containers: reading, sorting + splitting students, writing
template<typename StudentaiContainer>

void test1_containers(StudentaiContainer& studentai, int& suma, int nStud) {
	std::string filename = "studentai" + std::to_string(nStud) + ".txt";

	cout << "\n----TESTAVIMAS " << nStud << " STUDENTU IVESCIU----\n\n";

	//reading
	Timer t;
	StudentaiContainer studentai = read_file_testing(filename, suma);
	cout << "Duomenu nuskaitymas is failo " << filename << " uztruko: " << t.elapsed() << " s";
	system("pause");
	//sort by galutinisVid
	Timer t1;
	student_sort_testing(studentai);
	cout << "Studentu sort() " << filename << " uztruko: " << t1.elapsed() << " s";
	system("pause");

	//split students
	Timer t2;
	student_split_testing(filename, studentai);
	cout << "Studentu paskirstymas i 'gerus' ir 'blogus' " << filename << " uztruko: " << t2.elapsed() << " s";
	system("pause");
	
}
template <typename StudentaiContainer>
void do_test_containers(StudentaiContainer& studentai) {
	test1_containers(studentai,1000);
	test1_containers(studentai,10000);
	test1_containers(studentai,100000);
	test1_containers(studentai,1000000);
	test1_containers(studentai,10000000);
}