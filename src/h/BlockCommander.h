#ifndef BLOCKCOMMANDER_H
#define BLOCK_COMMANDER_H

#include <vector>
#include <string>

class BlockCommander {
    public:      
        std::vector<std::vector<int>> splitBlock(const std::string& filename, size_t blockSize, std::vector<std::string>& blockFiles);
        void readBlockFile(const std::string& filename);
        void writeBlock(const std::string& filename, const std::vector<int>& block);
    
    private:
        void saveBlockFiles(std::vector<std::string>& blockFiles, std::vector<int> block,size_t blockCount);
};



#endif