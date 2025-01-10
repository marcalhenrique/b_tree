#include <iostream>

#include "h/InputGenerator.h"
#include "h/BlockReader.h"

using namespace std;
int main(){
    const std::string filename = "input_data.txt";
    size_t blockSize = 997;
    std::vector<std::string> blockFiles;
    generateInputFile(filename, 3000, 0, 3000);
    BlockReader blockReader;
    blockReader.splitBlock(filename, blockSize, blockFiles);

    for (const std::string& blockFile: blockFiles) {
        std::cout << blockFile << std::endl;
    }

    return 0;
}