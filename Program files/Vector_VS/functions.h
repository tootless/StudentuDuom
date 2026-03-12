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

namespace fs = std::filesystem; //C++17

using std::cout;
using std::cin;

struct Studentas {
	std::string vardas, pav;
    std::vector<int> paz;
    int egzaminas = 0;
    double galutinisVid = 0;
    double galutinisMed = 0;

    //Darbas su failais
    static void write_studentai(const std::string filename, const std::vector<Studentas>& Studentai);

    //Darbas su ekranu
    void varpav_input();
    void paz_input(int& suma);
    void egz_input();
    void rand_paz(int& pazSk, int& suma);
    void rand_egz();
    void rand_varpav();
};

void menu(int& choiceMenu);
void number_input_validation(int& choice, int lowEnd, int highEnd, std::string optionalPrompt = "");
void string_input_validation(std::string& input, std::string optionalPrompt = "");
void student_sort();
void calculate_galutinis();

//Darbas su failais
std::vector<Studentas> read_file(std::string& filename, int& suma);
void student_file_generator(int nStud, int nPaz);
void split_file_generator(std::string& filename, std::vector<Studentas>& studentai);
void file_split(std::string filename);

//Testavimo funkcijos
void testing_v04_1(int nStud);
void testing_v04_2(std::vector<Studentas>& studentai, const std::string filename, int& suma);