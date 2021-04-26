//
// Created by User on 8.04.2020.
//

#include "Course.h"
using namespace std;

Course::Course(const unsigned int newCourseId, const string newTitle) {
    courseId = newCourseId;
    title = newTitle;
}
Course::~Course() {

}
unsigned int Course::getCourseId() const{
    return courseId;
}

string Course::getTitle() const{
    return title;
}


void Course::operator=(const class Course & right) {
    courseId = right.courseId;
    title = right.title;
}

ostream& operator<<(ostream &out, const Course &c) {
    out<< "\t" << c.courseId <<"\t\t";
    out<< c.title <<endl;
}