//
// Created by User on 7.05.2020.
//

#ifndef PARTB_TEAM_H
#define PARTB_TEAM_H
#include <string>
#include <iostream>
#include "Player.h"
using namespace std;
class Team{
public:
    Team(string aName = "", string aColor = "", int aYear = 0);
    ~Team();
    Team(const Team &tToCopy);
    Team& operator=(const Team& right);
    string getName();
    string getColor();
    int getYear();
    void setName(string aName);
    void setColor(string aColor);
    void setYear(int aYear);
    Player operator[]( const int index );
    void addPlayer( string pName, const string pPosition);
    void removePlayer( const string playerName );
    void displayTeam() const;
    bool showPlayer(const string pName, string& pPosition);

private:
    struct Node {
        Player p;
        Node* next;
    };
    Node *head;
    int playerCount;
    Node* findPlayer(const string playerName) const;
    string name;
    string color;
    int year;
};
#endif //PARTB_TEAM_H
