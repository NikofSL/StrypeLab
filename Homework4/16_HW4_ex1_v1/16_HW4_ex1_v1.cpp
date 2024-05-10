// 15_HW4_ex1.cpp
#include <iostream>
#include <limits>
#include "Students.h"

int getValidatedInteger() {
    int n;
    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            std::cerr << "Error: Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return n;
        }
    }
}

int main() {
    int option;
    StudentAttendance attendance;

    while (true) {
        std::cout << "1. Set attendance\n";
        std::cout << "2. Clear attendance\n";
        std::cout << "3. List students present\n";
        std::cout << "4. List students absent\n";
        std::cout << "5. Change attendance\n";
        std::cout << "6. Exit\n";

        option = getValidatedInteger();

        switch (option) {
        case 1:
            std::cout << "Enter student number to mark as present: ";
            attendance.mark_presence(getValidatedInteger());
            break;
        case 2:
            std::cout << "Enter student number to mark as absent: ";
            attendance.mark_absence(getValidatedInteger());
            break;
        case 3:
            std::cout << "Present students:\n";
            attendance.list_present_students();
            break;
        case 4:
            std::cout << "Absent students:\n";
            attendance.list_absent_students();
            break;
        case 5:
            std::cout << "Enter student number to toggle attendance: ";
            attendance.toggle_status(getValidatedInteger());
            break;
        case 6:
            return 0; // Exit the program
        default:
            std::cerr << "Invalid choice. Please choose between 1 and 6." << std::endl;
            break;
        }
    }
}
