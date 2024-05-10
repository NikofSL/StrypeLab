// Students.cpp
#include "Students.h"

void StudentAttendance::mark_presence(int student_number) {
    if (student_number >= 1 && student_number <= 64) {
        attendance_mask.set(student_number - 1, true);
        std::cout << "Student number " << student_number << " is marked as present.\n";
    }
}

void StudentAttendance::mark_absence(int student_number) {
    if (student_number >= 1 && student_number <= 64) {
        attendance_mask.set(student_number - 1, false);
        std::cout << "Student number " << student_number << " is marked as absent.\n";
    }
}

void StudentAttendance::list_absent_students() const {
    std::cout << "The numbers of absent students are:\n";
    for (int i = 0; i < 64; ++i) {
        if (!attendance_mask.test(i)) {
            std::cout << i + 1 << "\n";
        }
    }
}

void StudentAttendance::list_present_students() const {
    std::cout << "The numbers of students present are:\n";
    for (int i = 0; i < 64; ++i) {
        if (attendance_mask.test(i)) {
            std::cout << i + 1 << "\n";
        }
    }
}

void StudentAttendance::toggle_status(int student_number) {
    if (student_number >= 1 && student_number <= 64) {
        attendance_mask.flip(student_number - 1);
        std::cout << "The status of student number " << student_number << " has been changed.\n";
    }
}
