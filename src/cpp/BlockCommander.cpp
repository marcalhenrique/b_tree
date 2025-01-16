#include "../h/BlockCommander.h"
#include "../h/QuickSort.h"
#include "../h/SaveFiles.h"

std::vector<std::vector<int>> BlockCommander::splitBlock(const std::string& filename, size_t blockSize){
    std::ifstream inFile(filename);
    /*
     * @abrief Função para dividir o arquivo em blocos
        * @param filename: nome do arquivo  
        * @param blockSize: tamanho do bloco
        * @param blockFiles: vetor de strings que armazena os nomes dos arquivos
        * @return std::vector<std::vector<int>>: vetor de vetores de inteiros que armazena os blocos  
    */
    SaveFiles saveFiles;
    std::vector<std::vector<int>> blocks; // armazenar todos os blocos
    std::vector<int> block;
    int value;
    size_t blockCount = 0; // so pra nomear os arquivos

    while (inFile >> value) {
        block.push_back(value); //adiciona o valor no bloco

        if (block.size() == blockSize) {
            blocks.push_back(block);
            block.clear();
            blockCount++;
        }

    
    }

    //sobra de arquivo
    if (!block.empty()){
        blocks.push_back(block);
        block.clear();
    }


    for (size_t i = 0; i < blocks.size(); i++){
        std::string tempFilename = "block_files/disordered_block_" + std::to_string(i) + ".txt";
        saveFiles.saveFile(blocks[i], tempFilename);
        
    }

    return blocks;
}

std::vector<std::vector<int>> BlockCommander::sortBlocks(std::string filename, size_t blockSize){
    /*
     * @abrief Função para ordenar os blocos
        * @param filename: nome do arquivo  
        * @param blockSize: tamanho do bloco
        * @return std::vector<std::vector<int>>: vetor de vetores de inteiros que armazena os blocos ordenados   
    */
    SaveFiles saveFiles;
    QuickSort quickSort;
    std::vector<std::vector<int>> blocks = splitBlock(filename, blockSize);
    std::vector<std::vector<int>> sortedBlocks;
    std::vector<int> sortedBlock;


    for (size_t i = 0; i < blocks.size(); i++){
        sortedBlock = quickSort.sort(blocks[i], 0, blocks[i].size() - 1);
        sortedBlocks.push_back(sortedBlock);
        std::string tempFilename = "block_files/ordered_block_" + std::to_string(i) + ".txt";
        saveFiles.saveFile(sortedBlock, tempFilename);
    }
    
    return sortedBlocks;
}

