#include <iostream>
#include "SimpleReg.h"
#include "SimpleTeam.h"
using namespace std;
int main() {
    SimpleReg sr;
    sr.displayAllTeams();
    sr.addTeam("Galatasaray","Kirmizi",1905);
    sr.addTeam("faab","mavi",1903);
    sr.addTeam("bursaspor","mavi",1903);
    sr.addTeam("trabzonspor","mavi",1903);
    sr.addTeam("kiz","mavi",1903);

    sr.addTeam("gAlatasaray","Kizi",1905);
    sr.addTeam("genclerbirligi","mavi",1903);
    sr.addTeam("fBsdfs","mavi",1903);
    sr.displayAllTeams();
    sr.removeTeam("galatasaraY");
    sr.removeTeam("BursaSpor");
    sr.displayAllTeams();

    return 0;
}
