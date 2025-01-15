#include "h/InputGenerator.h"
#include "h/BlockCommander.h"

//TODO: Implementar a funcao de ordenação.

using namespace std;
int main(){
    const std::string filename = "input_data.txt";

    // gerar arquivo de entrada
    size_t blockSize = 997;
    std::vector<std::string> blockFiles;
    generateInputFile(filename, 3000, 0, 3000);

    // criar pasta para os blocos
    
    std::vector<std::vector<int>> blocks;
    BlockCommander blockCommander;
    blocks = blockCommander.splitBlock(filename, blockSize, blockFiles);

    // for (size_t i = 0; i < blocks.size(); i++) {
    //     std::cout << "Block " << i << ": " << std::endl;
    //     for (int num: blocks[i]) {
    //         std::cout << num << " ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}