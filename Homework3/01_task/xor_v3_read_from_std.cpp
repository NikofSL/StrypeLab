#include <iostream>

int main() {
    int num1, num2;

    auto isValid = [](int num) -> bool {
        return num == 0 || num == 1;
    };

    if (!(std::cin >> num1) || !isValid(num1)) {
        std::cerr << "Error: Invalid input. Please enter 0 or 1." << std::endl;
        return 1;
    }

    if (!(std::cin >> num2) || !isValid(num2)) {
        std::cerr << "Error: Invalid input. Please enter 0 or 1." << std::endl;
        return 1;
    }

    int result = num1 ^ num2;

    std::cout << "Result of XOR operation between " << num1 << " and " << num2 << " is: " << res>

    return 0;
}
