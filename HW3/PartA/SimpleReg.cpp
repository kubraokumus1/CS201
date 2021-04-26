//
// Created by User on 7.05.2020.
//


#include "SimpleReg.h"
SimpleReg::SimpleReg() {
    teamCount = 0;
    head = NULL;
}

SimpleReg::~SimpleReg() {
    Node * cur;
    for(int i = 0; i <teamCount; i++){
        cur = head;
        head = head->next;
        cur->next = NULL;
        delete cur;
    }
    cur = NULL;
}

void SimpleReg::addTeam(const string tName, const string tColor, const int tyear) {
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
                cout << "Warning: Team name "<< tName <<" is already occupied" << endl;
            else{
                Node * cur = head;
                for(int i = 0; i < teamCount-1; ++i){
                    cur = cur->next;
                }
                cur->next = new Node();
                cur->next->t = Team(tName, tColor, tyear);
                cur->next->next = NULL;
                teamCount++;
                cout << "Team "<< tName <<" has been added" << endl;
            }
        }

    }
}

void SimpleReg::removeTeam(const string teamName) {
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

void SimpleReg::displayAllTeams() const {
    if(head) {
        cout<<"------ALL TEAMS------"<<endl;
        Node *cur = head;
        for (int i = 0; i < teamCount; ++i) {
            cout<< i+1<<"-"<< cur->t;
            cur = cur->next;
        }
    } else
        cout<<"--EMPTY--";
    cout<<endl;
}

SimpleReg::Node *SimpleReg::findTeam(const string teamName) const {
    if(teamCount < 1 )
        return NULL;
    else{
        int check = 0;
        for (Node * cur = head; cur != NULL ; cur = cur->next) {
            if(cur->t.getName().length() == teamName. length()) {
                for (int i = 0; i < teamName.length(); i++)
                    if (toupper(cur->t.getName()[i]) == toupper(teamName[i]))
                        check ++;
            }
            if (check == teamName.length())
                return cur;
        }
     return NULL;
    }
}
