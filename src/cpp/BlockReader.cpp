#include "../h/BlockReader.h"

#include <fstream>
#include <iostream>

// TODO: Fazer uma função para salvar os blocos.

void BlockReader::splitBlock(const std::string& filename, size_t blockSize, std::vector<std::string>& blockFiles){
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    std::vector<int> block;
    int value;
    size_t blockCount = 0;

    while (inFile >> value) {
        block.push_back(value);

        if (block.size() == blockSize) {
            std::string tempFilename = "block_files/block_" + std::to_string(blockCount) + ".txt";
            blockFiles.push_back(tempFilename);
            std::ofstream outFile(tempFilename);
            for (int num: block) {
                outFile << num << "\n";
            }
            outFile.close();

            block.clear();
            blockCount++;
        }


    }

    if (!block.empty()){
        std::string tempFilename = "block_files/block_" + std::to_string(blockCount) + ".txt";
        blockFiles.push_back(tempFilename);
        std::ofstream outFile(tempFilename);
        for (int num: block) {
            outFile << num << "\n";
        }
        outFile.close();
    }

    inFile.close();
    std::cout << "File split into " << blockFiles.size() << " blocks." << std::endl;
}

