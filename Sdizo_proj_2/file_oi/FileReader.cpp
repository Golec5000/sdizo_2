#include "FileReader.h"


std::vector<std::vector<int>> FileReader::readNumbers(std::string fileName) {
    std::vector<std::vector<int>> helper;

    std::ifstream file(fileName);

    if(file.is_open()){
        std::string line;

        while (std::getline(file,line)){
            std::vector<int> numbers;
            std::stringstream ss(line);

            int num;
            while (ss >> num){
                numbers.push_back(num);
            }

            helper.push_back(numbers);
        }

        file.close();
        std::cout << "File reading - succesed" << std::endl << std::endl;
    } else {
        std::cout << "File reading - failed" << std::endl << std::endl;
    }

    return helper;
}
