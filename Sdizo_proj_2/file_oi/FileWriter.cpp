#include "FileWriter.h"

void FileWriter::save(std::basic_string<char> wynik) {
    std::ofstream file("..\\test_results\\wyniki.txt", std::ios::app);

    if (file.is_open()) {

        file << wynik << std::endl;

        file.close(); // Zamknij plik
    }
}
