// 16_HW4_ex1_v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <cstdint>


int main() {
    uint64_t attendance = 0; 
    int option;

    while (true) { 
        std::cout << "1. Set attendance" << std::endl;
        std::cout << "2. Clear attendance" << std::endl;
        std::cout << "3. Attendance info" << std::endl;
        std::cout << "4. Change attendance" << std::endl;
        std::cout << "5. Exit" << std::endl;

        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == 1) {
            std::cout << "Enter student number (1-64) to mark as present: ";
            int studentNumber;
            std::cin >> studentNumber;
            if (studentNumber >= 1 && studentNumber <= 64) {
                attendance |= (1ULL << (studentNumber - 1)); 
                std::cout << "Student " << studentNumber << " marked as present." << std::endl;
            }
            else {
                std::cerr << "Invalid student number." << std::endl;
            }
        }
        else if (option == 2) {
            std::cout << "Enter student number (1-64) to mark as absent: ";
            int studentNumber;
            std::cin >> studentNumber;
            if (studentNumber >= 1 && studentNumber <= 64) {
                attendance &= ~(1ULL << (studentNumber - 1));
                std::cout << "Student " << studentNumber << " marked as absent." << std::endl;
            }
            else {
                std::cerr << "Invalid student number." << std::endl;
            }
        }
        else if (option == 3) {
            std::cout << "Attendance info:" << std::endl;
            for (int i = 0; i < 64; ++i) {
                if (attendance & (1ULL << i)) {
                    std::cout << "Student " << (i + 1) << " is present." << std::endl;
                }
                else {
                    std::cout << "Student " << (i + 1) << " is absent." << std::endl;
                }
            }
        }
        else if (option == 4) {
            std::cout << "Enter student number (1-64) to toggle attendance: ";
            int studentNumber;
            std::cin >> studentNumber;
            if (studentNumber >= 1 && studentNumber <= 64) {
                attendance ^= (1ULL << (studentNumber - 1));
                std::cout << "Student " << studentNumber << " attendance status toggled." << std::endl;
            }
            else {
                std::cerr << "Invalid student number." << std::endl;
            }
        }
        else if (option == 5) {
            std::cout << "Exiting..." << std::endl;
            break; // Exit the loop
        }
        else {
            std::cerr << "Invalid option. Please choose a valid number (1-5)." << std::endl;
        }
    }

    return 0;
}
