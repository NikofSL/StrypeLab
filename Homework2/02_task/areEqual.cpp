#include <iostream>
#include <cmath>
#include <limits> // for numeric_limits
#include <string>

// Function to validate if input is a float
bool isValidFloat(const std::string& input, float& value) {
    try {
        value = std::stof(input);
        return true;
    }
    catch (const std::invalid_argument&) {
        return false;
    }
    catch (const std::out_of_range&) {
        return false;
    }
}

// Standard comparison
bool standardComparison(const float& a, const float& b) {
    return a == b;
}

// Comparison with epsilon
bool areApproximatelyEqual(const float& a, const float& b, float epsilon) {
    return std::abs(a - b) < epsilon;
}

// Bitwise comparison
bool bitwiseComparison(const float& a, const float& b) {
    int intA = *reinterpret_cast<const int*>(&a);
    int intB = *reinterpret_cast<const int*>(&b);
    return intA == intB;
}

// Comparison of surrounding numbers
bool comparisonOfSurroundingNumbers(const float& a, const float& b, int maxDifference) {
    int intA = *reinterpret_cast<const int*>(&a);
    int intB = *reinterpret_cast<const int*>(&b);
    return std::abs(intA - intB) <= maxDifference;
}

void menu() {
    std::cout << "Select comparison method:\n";
    std::cout << "1. Standard Comparison (==)\n";
    std::cout << "2. Comparison with Epsilon (tolerance)\n";
    std::cout << "3. Bitwise Comparison\n";
    std::cout << "4. Comparison of Surrounding Numbers\n";
}

int main() {
    float num1 = 0.0f, num2 = 0.0f;
    std::string input;

    std::cout << "Enter the first float number: ";
    std::getline(std::cin, input);
    if (!isValidFloat(input, num1)) {
        std::cerr << "Invalid input, expected a float number.\n";
        return 1;
    }

    std::cout << "Enter the second float number: ";
    std::getline(std::cin, input);
    if (!isValidFloat(input, num2)) {
        std::cerr << "Invalid input, expected a float number.\n";
        return 1;
    }

    float epsilon;
    int choice;
    int maxBitDifference;

    menu(); // Display menu
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    switch (choice) {
    case 1: // Standard comparison
        if (standardComparison(num1, num2)) {
            std::cout << "The numbers are exactly equal (standard comparison).\n";
        }
        else {
            std::cout << "The numbers are not exactly equal (standard comparison).\n";
        }
        break;

    case 2: // Comparison with epsilon
        std::cout << "Enter epsilon (tolerance): ";
        std::cin >> epsilon;
        if (areApproximatelyEqual(num1, num2, epsilon)) {
            std::cout << "The numbers are approximately equal (epsilon comparison).\n";
        }
        else {
            std::cout << "The numbers are not approximately equal (epsilon comparison).\n";
        }
        break;

    case 3: // Bitwise comparison
        if (bitwiseComparison(num1, num2)) {
            std::cout << "The numbers are bitwise equal.\n";
        }
        else {
            std::cout << "The numbers are not bitwise equal.\n";
        }
        break;

    case 4: // Comparison of surrounding numbers
        std::cout << "Enter maximum bitwise difference: ";
        std::cin >> maxBitDifference;
        if (comparisonOfSurroundingNumbers(num1, num2, maxBitDifference)) {
            std::cout << "The numbers are within the specified bitwise range.\n";
        }
        else {
            std::cout << "The numbers are not within the specified bitwise range.\n";
        }
        break;

    default:
        std::cout << "Invalid choice.\n";
        break;
    }

    return 0;
}
