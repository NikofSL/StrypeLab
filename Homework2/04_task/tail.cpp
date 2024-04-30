#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

void tail(const std::string& filename, int num_lines) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << "\n";
        return;
    }

    std::vector<std::string> lines;
    std::string line;


    while (std::getline(file, line)) {
        lines.push_back(line);
    }


    int total_lines = lines.size();
    int start_line = std::max(0, total_lines - num_lines);


    for (int i = start_line; i < total_lines; ++i) {
        std::cout << lines[i] << "\n";
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [-n lines] filename\n";
        return 1;
    }

    int num_lines = 10; 
    std::string filename;

   
    if (argc >= 3 && std::string(argv[1]) == "-n") {
        num_lines = std::stoi(argv[2]);
        filename = argv[3];
    }
    else {
        filename = argv[1];
    }

    tail(filename, num_lines);

    return 0;
}
