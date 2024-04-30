#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [-n lines] filename\n";
        return 1;
    }

    int num_lines = 10; 
    std::string filename;

    if (argc >= 3 && std::string(argv[1]) == "-n") {
        num_lines = std::atoi(argv[2]);
        filename = argv[3];
    }
    else {
        filename = argv[1];
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << "\n";
        return 1;
    }

    std::string line;
    int count = 0;

    while (count < num_lines && std::getline(file, line)) {
        std::cout << line << "\n";
        ++count;
    }

    file.close();
    return 0;
}
