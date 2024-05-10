// Students.h
#ifndef STUDENT_ATTENDANCE_H
#define STUDENT_ATTENDANCE_H

#include <iostream>
#include <bitset>

class StudentAttendance {
private:
    std::bitset<64> attendance_mask;

public:
    void mark_presence(int student_number);
    void mark_absence(int student_number);
    void list_absent_students() const;
    void list_present_students() const;
    void toggle_status(int student_number);
};

#endif  // STUDENT_ATTENDANCE_H
