//Studentas struct function declarations
#pragma once

#include <string>
#include <vector>

struct Studentas {
	std::string vardas, pav;
    std::vector<int> paz;
    int egzaminas = 0;
    double galutinisVid = 0;
    double galutinisMed = 0;

    //Darbas su failais
    static std::vector<Studentas> read_file(const std::string filename, int& suma);
    static void write_file(const std::string filename, const std::vector<Studentas>& Studentai);

    //Darbas su ekranu
    void varpav_input();
    void paz_input(int& suma);
    void egz_input();
    void rand_paz(int pazSk, int& suma);
    void rand_egz();
    void rand_stud();
};

void menu();
void input_validation(int& choice, int lowEnd, int highEnd, std::string optionalPrompt = "");