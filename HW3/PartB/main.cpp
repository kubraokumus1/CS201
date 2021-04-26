#include <iostream>
#include "Team.h"
#include "CompleteReg.h"

int main() {
    Team t;
    CompleteReg rg;
    rg.displayAllTeams();
    rg.displayTeam("gs");
    rg.addPlayer("hj","","");
    rg.addTeam("gs","kirmizisari",105);
    rg.addTeam("Gs","kirmizisari",1905);
    rg.addTeam("bursas","kirmizisari",1905);
    rg.addTeam("trabzons","kirmizisari",1905);
    rg.addTeam("gencler Birligi","kirmizisari",1905);
    rg.addTeam("gs","kirmizisari",1905);
    rg.addTeam("gs","kirmizisari",1905);
    rg.addTeam("gs","kirmizisari",1905);
    rg.addPlayer("Gs","hasan","guard");
    rg.addPlayer("fb","hasan","guard");
    rg.addPlayer("gs","faruk","guard");
    rg.addPlayer("bursas","hasan","guard");
    rg.displayAllTeams();
    rg.displayTeam("gs");
    rg.removePlayer("gs","HaSan");
    rg.displayPlayer("hasan");
    rg.displayTeam("gs");
    rg.removeTeam("gs");
    rg.displayAllTeams();
    cout << rg[0][0].getPosition() << endl;



    rg.displayTeam("gs");

    CompleteReg copy = rg;
    copy.displayAllTeams();
    CompleteReg hey;
    hey.addTeam("asd", "sad", 1900);
    hey.displayAllTeams();
    hey = rg;
    hey.displayAllTeams();

    return 0;
}
