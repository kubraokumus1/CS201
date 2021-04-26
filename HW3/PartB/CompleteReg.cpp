//
// Created by User on 7.05.2020.
//
#include "CompleteReg.h"

CompleteReg::CompleteReg() {
    head = NULL;
    teamCount = 0;
}

CompleteReg::~CompleteReg() {
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

CompleteReg::CompleteReg(const CompleteReg &systemToCopy) {
    if(!systemToCopy.head)
        head = NULL;
    else{
        head = new Node();
        head->t = systemToCopy.head->t;
        Node *newPtr = head;
        for (Node * rightPtr = systemToCopy.head->next; rightPtr != NULL; rightPtr = rightPtr->next) {
            newPtr->next = new Node();
            newPtr = newPtr->next;
            newPtr->t = rightPtr->t;
        }
        newPtr->next = NULL;
    }
    teamCount = systemToCopy.teamCount;
}

CompleteReg &CompleteReg::operator=(const CompleteReg &right) {
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
    if(!right.head)
        head = NULL;
    else{
        head = new Node();
        head->t = right.head->t;
        Node *newPtr = head;
        for (Node * rightPtr = right.head->next; rightPtr != NULL; rightPtr = rightPtr->next) {
            newPtr->next = new Node();
            newPtr = newPtr->next;
            newPtr->t = rightPtr->t;
        }
        newPtr->next = NULL;
    }
    teamCount = right.teamCount;
    return *this;
}

Team &CompleteReg::operator[](const int index) {
    if(index >= 0 && index < teamCount) {
        Node *cur = head;
        for (int i = 0; i < index ; ++i) {
            cur = cur->next;
        }
        return cur->t;
    }
}

void CompleteReg::addTeam(const string tName, const string tColor, const int tyear) {
    if(tyear < 1800 || tyear > 2020)
        cout << "Warning: "<< tyear <<" is not a valid foundation year" << endl;
    else{
        if (head == NULL) {
            head = new Node();
            head->t = Team(tName, tColor, tyear);
            head->next = NULL;
            teamCount++;
            cout << "Team "<< tName <<" has been added" << endl;
        }
        else{
            if(findTeam(tName))
                cout << "Warning: Team name "<< tName <<" is already exist." << endl;
            else{
                if(teamCount == 1){
                    head->next = new Node();
                    head->next->t= Team(tName, tColor, tyear);
                    head->next->next = NULL;
                }
                else {
                    Node *cur = head;
                    for (int i = 0; i < teamCount - 1; ++i) {
                        cur = cur->next;
                    }
                    cur->next = new Node();
                    cur->next->t = Team(tName, tColor, tyear);
                    cur->next->next = NULL;
                }
                teamCount++;
                cout << "Team "<< tName <<" has been added" << endl;
            }
        }
    }
}

void CompleteReg::removeTeam(string teamName) {
    if(!findTeam(teamName))
        cout<<"Warning: "<< teamName << " does not exist"<<endl;
    else{
        Node * cur = findTeam(teamName);
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
        teamCount--;
        cout<<"Team "<< teamName <<" has been removed"<<endl;
    }
}

void CompleteReg::displayAllTeams() const {
    if(head) {
        cout<<"------------------------------\n      ~ ALL TEAMS ~"<<endl;
        Node *cur = head;
        for (int i = 0; i < teamCount; ++i) {
            cout<< i+1<<"-";
            cout<< cur->t.getName() << ", ";
            cout<< cur->t.getColor() <<", ";
            cout<< cur->t.getYear() << endl;
            cur = cur->next;
        }
    } else
        cout<<"--EMPTY--";
    cout<<endl;
}

void CompleteReg::addPlayer(const string tName, const string pName, const string pPosition) {
    if(!findTeam(tName))
        cout << "Warning: There is no such team as " << tName << endl;
    else {
        findTeam(tName)->t.addPlayer(pName, pPosition);
    }
}

void CompleteReg::removePlayer(const string teamName, const string playerName) {
    if(!findTeam(teamName))
        cout << "Warning: There is no such team as " << teamName << endl;
    else
        findTeam(teamName)->t.removePlayer(playerName);
}

void CompleteReg::displayTeam(const string teamName) const {
    if(findTeam(teamName)) {
        cout << "------------------------------\n";
        findTeam(teamName)->t.displayTeam();
    }
    else
        cout << "Team " << teamName << " does not exist." << endl;
}

void CompleteReg::displayPlayer(const string playerName) const {
    if(head){
        Node* cur = head;
        int control = 0;
        string position = "";
        for (int i = 0; i < teamCount; ++i) {
            if(cur->t.showPlayer(playerName, position) ){
                control++;
                if(control == 1)
                    cout << "------------------------------\n" << playerName << endl;
                cout << position << ", ";
                cout << cur->t.getName() << ", ";
                cout << cur->t.getColor()<< ", ";
                cout << cur->t.getYear() << endl;
            }
            cur = cur->next;
        }
        if( control == 0)
            cout << "------------------------------\nWarning: Player " << playerName << " does not exist." << endl;
    }
    cout<<endl;
}


CompleteReg::Node *CompleteReg::findTeam(string teamName) const {
    if(teamCount <= 0 )
        return NULL;
    else{
        int check = 0;
        for (Node * cur = head; cur != NULL ; cur = cur->next) {

            if(cur->t.getName().length() == teamName. length()) {
                for (int i = 0; i < teamName.length(); i++){
                    if (toupper(cur->t.getName()[i]) == toupper(teamName[i]))
                        check ++;
                }
            }
            if (check == teamName.length())
                return cur;
        }
        return NULL;
    }
}
