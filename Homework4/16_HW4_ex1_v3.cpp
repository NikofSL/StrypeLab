#include <iostream>
#include <bitset>
#include <limits>
#include <cstdint>

const int MAX_STUDENTS = 64;

bool isValidStudentNumber(int studentNumber) {
    return studentNumber >= 1 && studentNumber <= MAX_STUDENTS;
}

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

void setAttendance(uint64_t& attendance) {
    std::cout << "Enter student number (1-64) to mark as present: ";
    int studentNumber = getValidatedInteger();
    if (isValidStudentNumber(studentNumber)) {
        attendance |= (1ULL << (studentNumber - 1));
        std::cout << "Student " << studentNumber << " marked as present." << std::endl;
    }
    else {
        std::cerr << "Invalid student number." << std::endl;
    }
}

void clearAttendance(uint64_t& attendance) {
    std::cout << "Enter student number (1-64) to mark as absent: ";
    int studentNumber = getValidatedInteger();
    if (isValidStudentNumber(studentNumber)) {
        attendance &= ~(1ULL << (studentNumber - 1));
        std::cout << "Student " << studentNumber << " marked as absent." << std::endl;
    }
    else {
        std::cerr << "Invalid student number." << std::endl;
    }
}

void listAttendanceInfo(const uint64_t& attendance, bool showPresent) {
    std::cout << (showPresent ? "Present students:" : "Absent students:") << std::endl;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        bool isPresent = attendance & (1ULL << i);
        if ((showPresent && isPresent) || (!showPresent && !isPresent)) {
            std::cout << "Student " << (i + 1) << std::endl;
        }
    }
}

void toggleAttendance(uint64_t& attendance) {
    std::cout << "Enter student number (1-64) to toggle attendance: ";
    int studentNumber = getValidatedInteger();
    if (isValidStudentNumber(studentNumber)) {
        attendance ^= (1ULL << (studentNumber - 1));
        std::cout << "Student " << studentNumber << " attendance status toggled." << std::endl;
    }
    else {
        std::cerr << "Invalid student number." << std::endl;
    }
}

int main() {
    uint64_t attendance = 0;
    int option;

    while (true) {
        std::cout << "1. Set attendance" << std::endl;
        std::cout << "2. Clear attendance" << std::endl;
        std::cout << "3. List present students" << std::endl;
        std::cout << "4. List absent students" << std::endl;
        std::cout << "5. Toggle attendance" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Choose an option: ";
        option = getValidatedInteger();

        switch (option) {
        case 1:
            setAttendance(attendance);
            break;
        case 2:
            clearAttendance(attendance);
            break;
        case 3:
            listAttendanceInfo(attendance, true);
            break;
        case 4:
            listAttendanceInfo(attendance, false);
            break;
        case 5:
            toggleAttendance(attendance);
            break;
        case 6:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cerr << "Invalid option. Please choose between 1 and 6." << std::endl;
            break;
        }
    }

    return 0;
}
