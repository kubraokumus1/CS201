//
// Created by User on 8.04.2020.
//

#include "RegistrationSystem.h"
using namespace std;
RegistrationSystem::RegistrationSystem() {
    students = NULL;
    courses = NULL;
    numOfStudents = 0;
    numOfCourses = 0;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName)
{
    if(firstName== "" || lastName == "")
        cout<<"Warning: Student name can not be empty" <<endl;
    else if(!students){
        students = new Student[1];
        numOfStudents++;
        students[0] = Student(studentId, firstName, lastName);
        cout << "Student "<< studentId <<" has been added" << endl;
    }
    else {
        bool check = false;
        for (int j = 0; j < numOfStudents; ++j)
        {
            if(students[j].getId() == studentId)
                check = true;
        }
        if(check){
            cout<< "Student "<< studentId <<" already exists"<<endl;
        }
        else {
            Student *temp = new Student[numOfStudents + 1];
            int i = 0;
            for (i; i < numOfStudents && students[i].getId() < studentId; i++) {
                temp[i] = students[i];
            }
            temp[i] = Student(studentId, firstName, lastName);

            for (i; i < numOfStudents; i++) {
                temp[i + 1] = students[i];
            }
            delete[] students;
            students = temp;
            temp = NULL;
            numOfStudents++;
            cout << "Student "<< studentId <<" has been added" << endl;
        }
    }
}

RegistrationSystem::~RegistrationSystem() {
    if(students){
        delete[] students;
    }
    if(courses){
        delete[] courses;
    }
}

void RegistrationSystem::deleteStudent(const int studentId) {
    bool exists = false;
    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].getId() == studentId) {
            exists = true;
        }
    }
    if (exists) {
        if (numOfStudents == 1){
            delete[] students;
            numOfStudents--;
            students = NULL;
        }
        else {
            Student *temp;
            temp = new Student[numOfStudents - 1];
            int i = 0;
            for (i; students[i].getId() != studentId; i++) { // before it finds the id
                temp[i] = students[i];                     // transfer the students to the same indexes
            }
            for (i; i < numOfStudents - 1; i++) //after it finds the id
                temp[i] = students[i + 1];
            delete[] students;
            numOfStudents--;
            students = temp;
            temp = NULL;
        }
        cout << "Student " << studentId << " has been deleted" << endl;
    }
    else {
        cout << studentId << " does not exist " <<  endl;
    }
}

void RegistrationSystem::showAllStudents() {
    if(numOfStudents < 1)
        cout<< "There is no students in the system"<<endl;
    else {
        cout << "Student ID\t" << "First Name\t" << "Last Name" << endl;
        cout << "-----------------------------------------" << endl;
        for (int i = 0; i < numOfStudents; i++)
            cout << students[i];
        cout << endl;
    }
}

void RegistrationSystem::showStudent(const int studentId) {
    bool exists = false;
    for(int i = 0; i < numOfStudents; i++) {
        if (students[i].getId() == studentId) {
            cout<< "Student ID\t" << "First Name\t" << "Last Name" << endl;
            cout<< "-----------------------------------------" << endl;
            cout << students[i];
            cout << endl;
            exists = true;
        }
    }
    if(!exists)
        cout<<"Student " << studentId << " does not exists"<<endl;
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName)
{
    bool exists = false;
    int s;
    for(int i = 0; i < numOfStudents; i++)
    {
        if (students[i].getId() == studentId)
        {
            s = i;
            exists = true;
        }
    }
    if(!exists)
        cout<<"Student " << studentId << " does not exists"<<endl;
    else {
        students[s].addCourse(courseId, courseName);
        bool exist = false;
        for (int i = 0; i < numOfCourses; i++){
            if(courses[i].getCourseId() == courseId)
                exist = true;
        }
        if(!exist){

            if(numOfCourses == 0){
                courses = new Course[1];
                courses[0] = Course(courseId, courseName);
                numOfCourses++;
            }
            else{
                Course* temp = new Course[numOfCourses + 1];
                for(int i = 0; i < numOfCourses; i++){
                    temp[i] = courses[i];
                }
                temp[numOfCourses] = Course(courseId, courseName);
                delete[] courses;
                courses = temp;
                temp = NULL;
                numOfCourses++;
            }
        }
    }
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
    bool exists = false;
    for(int i = 0; i < numOfStudents; i++){
        if(students[i].getId() == studentId){
            exists = true;
            if ((students[i].withdrawCourse(courseId)))
                cout<< "Student "<< studentId <<" has been withdrawn from course "<< courseId << endl;
            else
                cout<<"Student " << studentId <<" is not enrolled in course " << courseId << endl;
        }
    }
    if(!exists)
        cout << "Student " << studentId <<" does not exist" << endl;
}

void RegistrationSystem::cancelCourse(const int courseId) {
    bool exist = false;
    int j;
    for (int i = 0; i < numOfCourses; i++){
        if(courses[i].getCourseId() == courseId) {
            exist = true;
            j = i;
        }
    }
    if(exist){
        for(int i = 0; i < numOfStudents; i++){
            if((students[i].withdrawCourse(courseId)))
                ;
        }
        cout << "Course " << courseId << " has been cancelled" << endl;
        Course *temp = new Course[numOfCourses - 1];
        for (int k = 0; k < j; k++) {
            temp[k] = courses[k];
        }
        for (int k = j; k < numOfCourses - 1; k++) {
            temp[k] = courses[k + 1];
        }
        delete[] courses;
        courses = temp;
        numOfCourses--;
        temp = NULL;
    }
    else{
        cout << "Course " << courseId << " does not exist" << endl;
    }
}

void RegistrationSystem::showCourse(const int courseId) {
    bool exists = false;
    for (int j = 0; j < numOfCourses; ++j) {
        if(courses[j].getCourseId() == courseId) {
            exists = true;
            cout << "Course Id\tCourse name " << endl;
            cout << courseId << "\t\t" << courses[j].getTitle() << endl;
            cout << "\tStudent id\tFirst name\tLast name" << endl;
        }
    }
    if(!exists)
        cout << "Course " << courseId << " does not exist" << endl;
    else{
        for (int i = 0; i < numOfStudents; ++i) {
            if(students[i].showCourseInfo(courseId))
                ;
        }
    }
}
