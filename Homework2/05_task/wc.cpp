#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  

struct WCResult {
    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
};

WCResult wc(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filename << "\n";
        return {};
    }

    WCResult result;
    std::string line;
    bool in_word = false;


    while (std::getline(file, line)) {
        result.line_count++;  
        result.char_count += line.size() + 1;  

        for (char c : line) {
            if (std::isspace(c)) {
                if (in_word) {
                    result.word_count++;
                    in_word = false;
                }
            }
            else {
                in_word = true;
            }
        }

        if (in_word) {
            result.word_count++;
            in_word = false;
        }
    }

    file.close();
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename\n";
        return 1;
    }

    std::string filename = argv[1];
    WCResult result = wc(filename);

    std::cout << "Lines: " << result.line_count << "\n";
    std::cout << "Words: " << result.word_count << "\n";
    std::cout << "Characters: " << result.char_count << "\n";

    return 0;
}
