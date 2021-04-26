#include <iostream>
#include "AlgebraicExpression.h"

int main() {
    string s1 = "(4+5)-2*4";
    string s2 ="5*8-2*(4+3)";
    string s3 ="3+8/4-(2-1)/7";
    string s4 ="9+6/(5-3*(4/3))";
    string s5 ="6+2-(2*(6+(9/3)))";
    string s6 ="8-5*(4+2-(3-1)*9)";
    string s7 = "(4+5)-2*4";
    string s8 ="(4+2-(3-1)*8)";
    string s9 ="6/7*(3+5(8-2))";
    string s10 ="/4+3*-528";

    string s11 = "/6-5*3/45";
    string s12 = "+3-5-8+37";

    cout << "prefix of "<< s7 <<" : "<<infix2prefix(s7) << endl;
    cout << "prefix of "<< s8 <<" : "<<infix2prefix(s8) << endl;
    cout << "prefix of "<< s9 <<" : "<<infix2prefix(s7) << endl;
    cout<< endl;

    cout << "evaluation of "<< s10 <<" : "<< evaluatePrefix(s10) << endl;
    cout << "evaluation of "<< s11 <<" : "<<evaluatePrefix(s11) << endl;
    cout << "evaluation of "<< s12 <<" : "<<evaluatePrefix(s12) << endl;

    cout<<endl;
    cout<< "infix \t\t\tprefix \t\t\tevaluation"<<endl;
    cout << s1 <<"\t\t" <<infix2prefix( s1 );
    cout << "\t\t\t"<<evaluatePrefix(infix2prefix( s1 )) << endl;
    cout << s2 <<"\t\t" <<infix2prefix( s2 );
    cout << "\t\t"<<evaluatePrefix(infix2prefix( s2 )) << endl;
    cout << s3 <<"\t\t" <<infix2prefix( s3 );
    cout << "\t\t"<<evaluatePrefix(infix2prefix( s3 )) << endl;
    cout << s4 <<"\t\t" <<infix2prefix( s4 );
    cout << "\t\t"<<evaluatePrefix(infix2prefix( s4 )) << endl;
    cout << s5 <<"\t" <<infix2prefix( s5 );
    cout << "\t\t"<<evaluatePrefix(infix2prefix( s5 )) << endl;
    cout << s6 <<"\t" <<infix2prefix( s6 );
    cout << "\t\t"<<evaluatePrefix(infix2prefix( s6 )) << endl;



    return 0;
}
