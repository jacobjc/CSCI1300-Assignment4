// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 4 (main)

#include <iostream>
using namespace std;
#include "assignment4.cpp";


//runs the other .cpp, assignment4
int main(void){
cout << similarityScore("football", "baseball") << endl;
cout << countMatches("CCGCCGCCGA", "CGC", .60) << endl;
cout << findBestMatch("CCGACGACGA", "CGC");
}
