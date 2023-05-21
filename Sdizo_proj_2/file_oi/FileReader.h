#ifndef DATASTRUCTURES_FILEREADER_H
#define DATASTRUCTURES_FILEREADER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include <vector>
#include <string>

class FileReader {
public:
    std::vector<std::vector<int>> readNumbers(std::string fileName);
};


#endif //DATASTRUCTURES_FILEREADER_H
