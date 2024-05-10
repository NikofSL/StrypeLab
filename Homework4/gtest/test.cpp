#include "pch.h"

#include <gtest/gtest.h>
#include "attendance_functions.h"  // Include the refactored functions

TEST(AttendanceTest, TestMarkPresent) {
    uint64_t attendance = 0;
    markPresent(attendance, 1);  // Mark student 1 as present
    ASSERT_TRUE(attendance & (1ULL << 0));  // Bit 0 should be set
}

TEST(AttendanceTest, TestMarkAbsent) {
    uint64_t attendance = 1;  // Student 1 is already present
    markAbsent(attendance, 1);  // Mark student 1 as absent
    ASSERT_FALSE(attendance & (1ULL << 0));  // Bit 0 should be cleared
}

TEST(AttendanceTest, TestToggleAttendance) {
    uint64_t attendance = 0;
    toggleAttendance(attendance, 1);  // Toggle student 1's attendance
    ASSERT_TRUE(attendance & (1ULL << 0));  // Bit 0 should be set
    toggleAttendance(attendance, 1);  // Toggle again
    ASSERT_FALSE(attendance & (1ULL << 0));  // Bit 0 should be cleared
}

TEST(AttendanceTest, TestInvalidStudentNumber) {
    uint64_t attendance = 0;
    ASSERT_THROW(markPresent(attendance, 65), std::invalid_argument);  // Invalid student number
    ASSERT_THROW(markAbsent(attendance, 0), std::invalid_argument);  // Invalid student number
}

TEST(AttendanceTest, TestListAttendance) {
    uint64_t attendance = 0;
    markPresent(attendance, 1);  // Mark student 1 as present
    markAbsent(attendance, 2);  // Ensure student 2 is absent
    std::string attendanceInfo = listAttendance(attendance);
    ASSERT_TRUE(attendanceInfo.find("Student 1 is present") != std::string::npos);
    ASSERT_TRUE(attendanceInfo.find("Student 2 is absent") != std::string::npos);
}
