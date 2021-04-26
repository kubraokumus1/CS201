//
// Created by User on 8.04.2020.
//

#include "Student.h"

using namespace std;

Student::Student( const unsigned int newId, const string newFirstName, const string newLastName){
    Id = newId;
    firstName = newFirstName;
    lastName = newLastName;
    numOfCourses = 0;
    courses = NULL;
}
Student::~Student()
{
    if(numOfCourses > 0){
        delete[] courses;
        courses = NULL;
    }
}
string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;
}
int Student::getId() const {
    return Id;
}
unsigned int Student::getNumOfCourses() const {
    return numOfCourses;
}

void Student::addCourse(const int courseId, const string courseName) {
    if(!courses){
        courses = new Course[1];
        courses[0] = Course(courseId, courseName);
        numOfCourses++;
        cout << "Course " << courseId << " has been added to student " << Id << endl;
    }
    else {
        bool enrolled = false; // to check whether the student is already enrolled in the course
        for (int i = 0; i < numOfCourses; i++) {
            if (courses[i].getCourseId() == courseId) {
                cout << "Student " << Id << " is already enrolled in course " << courseId << endl;
                enrolled = true;
            }
        }
        if (!enrolled) {
            Course *temp = new Course[numOfCourses + 1];
            for (int i = 0; i < numOfCourses; i++)
                temp[i] = courses[i];
            temp[numOfCourses] = Course(courseId, courseName);
            delete[] courses;
            courses = temp;
            temp = NULL;
            numOfCourses++;
            cout << "Course " << courseId << " has been added to student " << Id << endl;
        }
    }
}

void Student::operator=(const Student &right) {
    if(courses)
        delete[] courses;
    if(right.courses){
        courses = new Course[right.numOfCourses];
        for (int i = 0; i < right.numOfCourses; i++) {
            courses[i] = right.courses[i];
        }
    }
    else
        courses = NULL;
    firstName = right.firstName;
    lastName = right.lastName;
    Id = right.Id;
    numOfCourses = right.numOfCourses;
}

Course Student::getCourse(const unsigned int index) const {
    return courses[index];
}

ostream& operator<<(ostream &out, const Student &s) {
    out<< s.Id << "\t\t";
    out<< s.firstName << "\t\t";
    out<< s.lastName << endl;
    if(s.numOfCourses >= 1) {
        out<<"\tCourse Id\tCourse name"<<endl;
        for (int i = 0; i < s.numOfCourses; i++) {
            out << s.courses[i];
        }
    }
}

bool Student::showCourseInfo(const int courseId) {
    for (int i = 0; i < numOfCourses; ++i) {
        if(courses[i].getCourseId() == courseId ) {
            cout << "\t" << Id << "\t\t";
            cout << firstName << "\t\t";
            cout << lastName << endl;
            return true;
        }
    }
    return false;
}

bool Student::withdrawCourse(const int courseId) {
    for(int j = 0; j < numOfCourses; j++){
        if(courses[j].getCourseId() == courseId){
            if(numOfCourses == 1){
                delete[] courses;
                courses = NULL;
                numOfCourses--;
                return true;
            }
            else {
                Course *temp = new Course[numOfCourses - 1];
                for (int k = 0; k < j; k++) {
                    temp[k] = courses[k];
                }
                for (int k = j; k < numOfCourses - 1; k++) {
                    temp[k] = courses[k + 1];
                }
//                delete[] courses;
//                numOfCourses--;
//                courses = new Course[numOfCourses];
//                for (int i = 0; i < numOfCourses; ++i) {
//                    courses[i] = temp[i];
//                }
//                delete[] temp;
//                temp = NULL;
                delete[] courses;
                courses = temp;
                temp = NULL;
                numOfCourses--;
                return true;
            }
        }
    }
    return false;
}



