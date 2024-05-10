#pragma once

#include <bitset>
#include <cstdint>
#include <iostream>

// Maximum number of students
const int MAX_STUDENTS = 64;

// Function to validate a student number
bool isValidStudentNumber(int studentNumber) {
    return studentNumber >= 1 && studentNumber <= MAX_STUDENTS;
}

// Function to set a student as present
void markPresent(uint64_t& attendance, int studentNumber) {
    if (isValidStudentNumber(studentNumber)) {
        attendance |= (1ULL << (studentNumber - 1));
    }
    else {
        throw std::invalid_argument("Invalid student number");
    }
}

// Function to set a student as absent
void markAbsent(uint64_t& attendance, int studentNumber) {
    if (isValidStudentNumber(studentNumber)) {
        attendance &= ~(1ULL << (studentNumber - 1));
    }
    else {
        throw std::invalid_argument("Invalid student number");
    }
}

// Function to toggle a student's attendance status
void toggleAttendance(uint64_t& attendance, int studentNumber) {
    if (isValidStudentNumber(studentNumber)) {
        attendance ^= (1ULL << (studentNumber - 1));
    }
    else {
        throw std::invalid_argument("Invalid student number");
    }
}

// Function to list attendance information
std::string listAttendance(const uint64_t& attendance) {
    std::string result;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        result += "Student " + std::to_string(i + 1) + " is " + ((attendance & (1ULL << i)) ? "present" : "absent") + "\n";
    }
    return result;
}
