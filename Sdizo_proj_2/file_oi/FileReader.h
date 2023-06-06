#ifndef DATASTRUCTURES_FILEREADER_H
#define DATASTRUCTURES_FILEREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class FileReader {
public:
    std::vector<std::vector<int>> readNumbers(std::string fileName);
};


#endif //DATASTRUCTURES_FILEREADER_H
