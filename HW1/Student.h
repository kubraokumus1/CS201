//
// Created by User on 8.04.2020.
//

#ifndef HW1B_STUDENT_H
#define HW1B_STUDENT_H
#include <string>

#include <iostream>
#include "Course.h"
using namespace std;
class Student{
public:
    Student(const unsigned int newId = 0, const string newFirstName = "",
            const string newLastName = ""
    );
    ~Student();
    void operator=(const Student &right);
    int getId() const;
    unsigned int getNumOfCourses() const;
    bool showCourseInfo(const int courseId);
    string getFirstName() const;
    string getLastName() const;
    void addCourse(const int courseId, const string courseName );
    bool withdrawCourse(const int courseId);
    Course getCourse( const unsigned int index) const;
    friend ostream& operator<<(ostream& out, const Student& s);
private:
    int Id;
    string firstName;
    string lastName;
    Course* courses;
    unsigned int numOfCourses;
};
#endif //HW1B_STUDENT_H
