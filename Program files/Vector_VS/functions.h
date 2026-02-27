//Global functions declarations
#pragma once

#include <string>
#include <fstream>

void menu();
void input_validation(int& choice, int lowEnd, int highEnd, std::string optionalPrompt = "");