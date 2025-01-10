#include "../h/InputGenerator.h"

#include <iostream>
#include <fstream>
#include <cstdlib> // std::rand, std::srand
#include <ctime>


void generateInputFile(const std::string& filename, int values, int min, int max) {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    // definir a seed para o rand
    std::srand(std::time(nullptr)); // <- seed baseada no tempo, sempre numeros diferentes

    for (int i = 0; i < values; i++){
        int random = min + std::rand() % (max - min + 1);
        outFile << random << "\n";
    }

    outFile.close();
    std::cout << "File generated successfully!" << filename << std::endl;
}
