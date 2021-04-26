//
// Created by User on 7.05.2020.
//

#ifndef PARTB_PLAYER_H
#define PARTB_PLAYER_H
#include <string>
#include <iostream>
using namespace std;
class Player{
public:
    Player(string aName = "", string aPosition = "");
    ~Player();
    Player& operator=(const Player& right);
    string getName();
    string getPosition();
    void setName(string aName);
    void setPosition(string aPosition);
    friend ostream& operator<<(ostream& out, const Player& p);

private:
    string name;
    string position;
};
#endif //PARTB_PLAYER_H
