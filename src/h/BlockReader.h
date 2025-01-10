#ifndef BLOCKREADER_H
#define BLOCKREADER_H

#include <vector>
#include <string>

class BlockReader {
    public:
        void splitBlock(const std::string& filename, size_t blockSize, std::vector<std::string>& blockFiles);
};

#endif