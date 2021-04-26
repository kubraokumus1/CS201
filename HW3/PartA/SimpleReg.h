//
// Created by User on 7.05.2020.
//

#ifndef PARTA_SIMPLEREG_H
#define PARTA_SIMPLEREG_H
#include <string>
#include <iostream>
using namespace std;
#include "SimpleTeam.h"
class SimpleReg {
public:
    SimpleReg();
    ~SimpleReg();
    void addTeam( const string tName, const string tColor, const int tyear );
    void removeTeam( const string teamName );
    void displayAllTeams() const;
private:
    struct Node {
        Team t;
        Node* next;
    };
    Node *head;
    int teamCount;
    Node* findTeam(const string teamName) const;
};

#endif //PARTA_SIMPLEREG_H
