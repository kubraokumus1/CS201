//
// Created by User on 8.04.2020.
//

#ifndef HW1B_REGISTRATIONSYSTEM_H
#define HW1B_REGISTRATIONSYSTEM_H
#include "Course.h"
#include "Student.h"
using namespace std;
class RegistrationSystem {
public:
    RegistrationSystem();
    ~RegistrationSystem();
    void addStudent( const int studentId, const string firstName, const string lastName );
    void deleteStudent( const int studentId );
    void addCourse( const int studentId, const int courseId, const string courseName );
    void withdrawCourse( const int studentId, const int courseId );
    void cancelCourse( const int courseId );
    void showStudent( const int studentId );
    void showCourse( const int courseId );
    void showAllStudents();
private:
    Student* students;
    Course* courses;
    int numOfStudents;
    int numOfCourses;
};
#endif //HW1B_REGISTRATIONSYSTEM_H
