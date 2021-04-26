//
// Created by User on 8.04.2020.
//

#ifndef HW1B_COURSE_H
#define HW1B_COURSE_H
#include <string>
using namespace std;
#include <iostream>
class Course{
public:
    Course(const unsigned int newCourseId = 0, const string newTitle = "");
    //  Course(const Course &sToCopy);
    ~Course();
    void operator=(const Course &right);
    unsigned int getCourseId() const;
    string getTitle() const;
    friend ostream& operator<<(ostream& out, const Course& c);
private:
    unsigned int courseId;
    string title;

};
#endif //HW1B_COURSE_H
