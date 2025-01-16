#include "h/InputGenerator.h"
#include "h/BlockCommander.h"


//TODO: Implementar a funcao de ordenação.

int main(){
    const std::string filename = "input_data.txt";
    

    // gerar arquivo de entrada
    size_t blockSize = 997;
    std::vector<std::string> blockFiles;
    generateInputFile(filename, 3000, 0, 3000);

    
    std::vector<std::vector<int>> sortedBlocks;
    BlockCommander blockCommander;
    sortedBlocks = blockCommander.sortBlocks(filename, blockSize);

    return 0;
}