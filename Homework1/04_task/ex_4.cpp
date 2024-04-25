#include <iostream>
#include <sstream>  
#include <string>
#include <vector>
#include <algorithm> 
#include <limits>   

std::vector<double> splitAndConvert(const std::string& str) {
    std::istringstream iss(str);
    std::vector<double> numbers;
    double num;

    while (iss >> num) {
        numbers.push_back(num);
    }

    return numbers;
}

int main() {
    std::string line;
    std::vector<double> allNumbers;

    while (std::getline(std::cin, line)) {
        std::vector<double> numbers = splitAndConvert(line);

        allNumbers.insert(allNumbers.end(), numbers.begin(), numbers.end());
    }

    if (allNumbers.empty()) {
        std::cerr << "Error: No valid numbers found." << std::endl;
        return 1;
    }

    double max_num = *std::max_element(allNumbers.begin(), allNumbers.end());

    std::cout << "The largest number is: " << max_num << std::endl;

    return 0; 
}
