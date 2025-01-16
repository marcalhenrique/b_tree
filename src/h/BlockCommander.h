#ifndef BLOCKCOMMANDER_H
#define BLOCK_COMMANDER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

class BlockCommander {
    public:
        std::vector<std::vector<int>> sortBlocks(std::string filename, size_t blockSize);
    private:      
        std::vector<std::vector<int>> splitBlock(const std::string& filename, size_t blockSize);
        
};



#endif // BLOCKCOMMANDER_H