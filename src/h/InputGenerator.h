#ifndef INPUT_GENERATOR_H
#define INPUT_GENERATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib> // std::rand, std::srand
#include <ctime>

void generateInputFile(const std::string& filename, int values, int min, int max);

#endif // INPUT_GENERATOR_H