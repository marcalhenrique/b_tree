#include <iostream>
#include <filesystem>


#include "h/InputGenerator.h"
#include "h/BlockCommander.h"

using namespace std;
int main(){
    const std::string filename = "input_data.txt";

    size_t blockSize = 997;
    std::vector<std::string> blockFiles;
    generateInputFile(filename, 3000, 0, 3000);

    std::filesystem::create_directory("block_files");
    std::vector<std::vector<int>> blocks;
    BlockCommander blockCommander;
    blocks = blockCommander.splitBlock(filename, blockSize, blockFiles);

    return 0;
}