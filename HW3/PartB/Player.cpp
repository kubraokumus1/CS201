//
// Created by User on 7.05.2020.
//

#include "Player.h"

Player::Player(string aName, string aPosition) {
    name = aName;
    position = aPosition;
}

Player::~Player() {

}

Player &Player::operator=(const Player &right) {
    name = right.name;
    position = right.position;
    return * this;
}

string Player::getName() {
    return name;
}

string Player::getPosition() {
    return position;
}

void Player::setName(string aName) {
    name = aName;
}

void Player::setPosition(string aPosition) {
    position = aPosition;
}

ostream &operator<<(ostream &out, const Player &p) {
    out<< p.name << ", ";
    out<< p.position <<endl;
}

