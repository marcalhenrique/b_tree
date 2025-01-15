#include "../h/BlockCommander.h"

#include <fstream>
#include <iostream>

// TODO: Fazer uma função para salvar os blocos.

void BlockCommander::saveBlockFiles(std::vector<std::string>& blockFiles, std::vector<int> block ,size_t blockCount){
    /*  
     * @brief Função para salvar os blocos em arquivos
        * @param blockFiles: vetor de strings que armazena os nomes dos arquivos
        * @param block: vetor de inteiros que armazena os valores do bloco
        * @param blockCount: contador de blocos
    * @return void
    */

    std::string tempFilename = "block_files/block_" + std::to_string(blockCount) + ".txt";
    blockFiles.push_back(tempFilename);
    std::ofstream outFile(tempFilename);
    for (int num: block) {
        outFile << num << "\n";
    }
    outFile.close();

}



std::vector<std::vector<int>> BlockCommander::splitBlock(const std::string& filename, size_t blockSize, std::vector<std::string>& blockFiles){
    std::ifstream inFile(filename);
    /*
     * @abrief Função para dividir o arquivo em blocos
        * @param filename: nome do arquivo  
        * @param blockSize: tamanho do bloco
        * @param blockFiles: vetor de strings que armazena os nomes dos arquivos
        * @return std::vector<std::vector<int>>: vetor de vetores de inteiros que armazena os blocos  
    */

    if (!inFile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return {};
    }

    std::vector<std::vector<int>> blocks; // armazenar todos os blocos
    std::vector<int> block;
    int value;
    size_t blockCount = 0; // so pra nomear os arquivos

    while (inFile >> value) {
        block.push_back(value); //adiciona o valor no bloco

        if (block.size() == blockSize) {
            blocks.push_back(block);
            saveBlockFiles(blockFiles, block, blockCount);
            block.clear();
            blockCount++;
        }

    
    }

    //sobra de arquivo
    if (!block.empty()){
        blocks.push_back(block);
        saveBlockFiles(blockFiles, block, blockCount);
        block.clear();
    }

    inFile.close();
    std::cout << "File split into " << blockFiles.size() << " blocks." << std::endl;

    return blocks;
}

