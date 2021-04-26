//
// Created by User on 7.05.2020.
//

#ifndef PARTA_SIMPLETEAM_H
#define PARTA_SIMPLETEAM_H
#include <string>
#include <iostream>
using namespace std;
class Team{
public:
    Team(string aName = "", string aColor = "", int aYear = 0);
    ~Team();
    Team& operator=(const Team& right);
    string getName();
    string getColor();
    int getYear();
    void setName(string aName);
    void setColor(string aColor);
    void setYear(int aYear);
    friend ostream& operator<<(ostream& out, const Team& t);

private:
    string name;
    string color;
    int year;
};
#endif //PARTA_SIMPLETEAM_H
