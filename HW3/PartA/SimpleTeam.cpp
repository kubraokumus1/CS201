//
// Created by User on 7.05.2020.
//

#include "SimpleTeam.h"
using namespace std;

Team::Team(string aName, string aColor, int aYear) {
    name = aName;
    color = aColor;
    year = aYear;
}

Team::~Team() {
}

string Team::getName() {
    return name;
}

string Team::getColor() {
    return color;
}

int Team::getYear() {
    return year;
}

void Team::setName(string aName) {
    name = aName;
}

void Team::setColor(string aColor) {
    color = aColor;
}

void Team::setYear(int aYear) {
    year = aYear;
}

Team &Team::operator=(const Team &right) {
    name = right.name;
    color = right.color;
    year = right.year;

    return *this;
}

ostream &operator<<(ostream &out, const Team &t) {
    out<< t.name << ", ";
    out<< t.color <<", ";
    out<< t.year << endl;
}

