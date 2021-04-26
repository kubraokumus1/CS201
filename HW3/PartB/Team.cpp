//
// Created by User on 7.05.2020.
//
#include "Team.h"
using namespace std;

Team::Team(string aName, string aColor, int aYear) {
    name = aName;
    color = aColor;
    year = aYear;
    head = NULL;
    playerCount = 0;
}

Team::Team(const Team &tToCopy) {
    *this = tToCopy; ////////////////
}

Team::~Team() {
    if(head){
        Node * cur;
        while(head->next != NULL){
            cur = head;
            head = head->next;
            cur->next = NULL;
            delete cur;
        }
        delete head;
        head = NULL;
    }
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
    if(head)
        delete this;
    name = right.name;
    color = right.color;
    year = right.year;
    if(!right.head)
        head = NULL;
    else{
        head = new Node();
        head->p = right.head->p;
        Node *newPtr = head;
        for (Node * rightPtr = right.head->next; rightPtr != NULL; rightPtr = rightPtr->next) {
            newPtr->next = new Node();
            newPtr = newPtr->next;
            newPtr->p = rightPtr->p;
        }
        newPtr->next = NULL;
    }
    playerCount = right.playerCount;
    return *this;
}


Team::Node *Team::findPlayer(const string playerName) const {
    if(playerCount == 0 ) {
        return NULL;
    }
    else{
        int check = 0;
        for (Node * cur = head; cur != NULL ; cur = cur->next) {
            if(cur->p.getName().length() == playerName.length()) {
                for (int i = 0; i < playerName.length(); i++)
                    if (toupper(cur->p.getName()[i]) == toupper(playerName[i])) {
                        check++;
                    }
            }
            if (check == playerName.length())
                return cur;
        }
        return NULL;
    }
}

void Team::addPlayer(string pName, const string pPosition) {
    if (head == NULL) {
        head = new Node();
        head->p = Player(pName, pPosition);
        head->next = NULL;
        playerCount++;
        cout << "Player " << pName << " has been added to team " << name << endl;
    }
    else{
        if(findPlayer(pName)) {
            cout << "Warning: Player " << pName << " is already exist in " << name << endl;
        }
        else{
            Node * cur = head;
            for(int i = 0; i < playerCount-1; ++i){
                cur = cur->next;
            }
            cur->next = new Node();
            cur->next->p = Player(pName, pPosition);
            cur->next->next = NULL;
            playerCount++;
            cout << "Player " << pName << " has been added to team " << name << endl;
        }
    }
}

void Team::removePlayer(const string playerName) {
    if(!findPlayer(playerName))
        cout<<"Warning: "<< playerName << " does not exist"<<endl;
    else{
        Node * cur = findPlayer(playerName);
        if(cur == head)
            head = head->next;
        else {
            Node *prev = head;
            for (prev; prev->next != cur; prev = prev->next) {
            }
            prev->next = cur->next;
            prev =NULL;
        }
        cur->next = NULL;
        delete cur;
        cur = NULL;
        playerCount--;
        cout<<"Player "<< playerName <<" has been removed from the team " << name <<endl;
    }
}

void Team::displayTeam() const {
    cout<< name << ", ";
    cout<< color <<", ";
    cout<< year << endl;
    if (head) {
        cout<<"     ~ " << name << " PLAYERS ~"<<endl;
        Node *cur = head;
        for (int i = 0; i < playerCount; ++i) {
            cout<< i+1<<"-"<< cur->p;
            cur = cur->next;
        }
        cur = NULL;
    } else
        cout<<"--NO PLAYERS--";
    cout<<endl;
}

bool Team::showPlayer(const string pName, string& pPosition) {
    if(findPlayer(pName)) {
        pPosition = findPlayer(pName)->p.getPosition();
        return true;
    }
    else
        return false;
}

Player Team::operator[](const int index) {
    if(index >= 0 && index < playerCount) {
        Node *cur = head;
        for (int i = 0; i < index ; ++i) {
            cur = cur->next;
        }
        return cur->p;
    }
}




