#ifndef BLOCKCOMMANDER_H
#define BLOCK_COMMANDER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

class BlockCommander {
    public:      
        std::vector<std::vector<int>> splitBlock(const std::string& filename, size_t blockSize, std::vector<std::string>& blockFiles);
    
    private:
        void saveBlockFiles(std::vector<std::string>& blockFiles, std::vector<int> block,size_t blockCount);
        
};



#endif