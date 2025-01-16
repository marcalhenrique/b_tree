#ifndef SAVE_FILES_H
#define SAVE_FILES_H

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>

class SaveFiles{
    public:
        void saveFile(std::vector<int>& block, std::string tempFilename);
};



#endif // SAVE_FILES_H