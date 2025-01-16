#include "../h/SaveFiles.h"

void SaveFiles::saveFile(std::vector<int>& block, std::string tempFilename){

    std::filesystem::create_directory("block_files");
    std::ofstream outFile(tempFilename);
    if (!outFile){
        std::cerr << "Erro ao abrir o arquivo de saida" << std::endl;
        return;  
    }
    for (int value : block) {
        outFile << value << std::endl;
    }
    

}