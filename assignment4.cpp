// Author: Jacob Christiansen
// Recitation: 104 – Vipra Gupta
//
// Assignment 4

#include <iostream>
using namespace std;


//In this function, it is comparing two strings, and if they are equal in length, then
//they compare how similar they are to each other, based on matching 1-length strings.
//It then calculates the similarity score using the string lengths and the matching values.
//Then it returns the score.
float similarityScore(string seq1, string seq2){

float i;
float l1 = seq1.length();
float l2 = seq2.length();
float hamm = 0;
float score;

    if(l1 == l2){
        for(i = 0; i<l1; i++){
            string test1 = seq1.substr(i, 1);
            string test2 = seq2.substr(i,1);
                if(test1 != test2){
                    hamm++;
                }
            score = (l1 - hamm)/l1;

        }
    }else{
    score = 0;
    }

return score;
}

//This function is counting how many times a string finds matches of itself inside of another
//string, based on a certain, given, threshold. Using similarityScore, it calculates the score
//and counts a match if it is above the threshold.
//Then it returns the count number.
int countMatches(string geno, string seq1, float mScore){

    int i;
    int count = 0;

    if(mScore == 0.00){
        count = -2;
    }
        for(i =0; i<geno.length(); i++){

            string subGeno = geno.substr(i, seq1.length());
            float testScore = similarityScore(subGeno, seq1);
                if(testScore >= mScore){
                    count++;
                }
        }

    return count;
}

//Very similar to the description above, except the difference is that it is not counting every match,
//the function is comparing all the similarityScores, and finding the one which is highest, and returns
//that score.
float findBestMatch(string geno, string seq){

float hiScore = 0.0;
for(int i=0; i<geno.length(); i++){
    string subGeno = geno.substr(i, seq.length());
    float newScore = similarityScore(subGeno, seq);
        if (hiScore < newScore){
            hiScore = newScore;
        }
    }
return hiScore;
}

//This function is taking in 4 strings, 3 know genomes and 1 sequence.
//It simply is comparing the known to the sequence with findBestMatch, then it is comparing the
//returned values to find out which of the known genomes matched the sequence the BEST.
//Then based on which matched the best, or if they were equal, then it returns a specific value.
int findBestGenome(string g1, string g2, string g3, string seq){
    float geno1 = findBestMatch(g1, seq);
    float geno2 = findBestMatch(g2, seq);
    float geno3 = findBestMatch(g3, seq);
    if(geno1 > geno2 && geno1 > geno3){
        return 1;
    }
    else if(geno2 > geno1 && geno2 > geno3){
        return 2;
    }
    else if(geno3 > geno1 && geno3 > geno2){
        return 3;
    }
    else if(geno1 == geno2 && geno1 > geno3){
        return 0;
    }
    else if(geno3 == geno2 && geno1 > geno3){
        return 0;
    }
    else if(geno1 == geno3 && geno1 > geno2){
        return 0;
    }
    else if(geno1 == geno2 && geno1 == geno3){
        return 0;
    }
}

