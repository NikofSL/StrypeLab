#include <iostream>
#include <fstream> // For working with files

// Function to check if numbers are 0 or 1
bool isValidBinaryNumber(int num) {
    return num == 0 || num == 1;
}

// XOR operation function
int xorOperation(int a, int b) {
    return (a || b) && !(a && b); // XOR operation
}

int main() {
    std::ifstream file("numbers.txt"); // Open the file for reading

    if (!file.is_open()) { // Checking if the file was successfully opened
        std::cerr << "Error opening file." << std::endl;
        return 1; // Exit with error
    }

    int num1, num2;

    // Reading the two numbers from the file
    file >> num1 >> num2;

    // Check for invalid input
    if (file.fail() || !isValidBinaryNumber(num1) || !isValidBinaryNumber(num2)) {
        std::cerr << "Invalid input. The numbers must be 0 or 1." << std::endl;
        return 1; // Exit with error
    }

    file.close(); //Close the file

    // Perform the XOR operation and display the result
    int result = xorOperation(num1, num2);
    std::cout << "Result of XOR: " << result << std::endl;

    return 0; // Successful exit
}
