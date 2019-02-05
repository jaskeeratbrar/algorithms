#include <iostream>
#include <fstream>
#include <cmath>

#include <stdlib.h>
#include <stdio.h>


using namespace std;

string to_base(int number, int base, int param){

    string bases = "ACGT";
    string result = "";



    while (number > 0){
        result  = bases[number%base] + result;
        number /= base;
    }

    if(result.length() != param){
        int difference = param - result.length();

        int counter = 0;
        while(counter != difference){
            result = 'A' + result;
            counter  +=1;
        }
    }

    return result;

}

void thirdLine(const string& m, int& pam){

    if(m.length() < pam){
        cout << "error";
    }

    string intSeq;
    for (char is : m) {
        if ( is == 'A' ) {
            intSeq = intSeq.append("0");
        }
        if ( is == 'C' ) {
            intSeq = intSeq.append("1");
        }
        if ( is == 'G' ) {
            intSeq = intSeq.append("2");
        }
        if ( is == 'T' ) {
            intSeq = intSeq.append("3");
        }
        if ( is == 'N' ) {
            intSeq += "-";
        }
    }

    unsigned  int arrayLength = static_cast<unsigned int>(static_cast<int>(pow(4, pam)));


    int* kmer = new int[arrayLength+1];
    for (int l = 0; l <arrayLength+1 ; ++l) {
        kmer[l] = 0;
    }

    int count = 0;
    int arrayIndex = 0;
    string strCopy;
    for (int i = 0; i < intSeq.length(); ++i) {
        if(intSeq[i] != '-') {
            if ( count != pam  ) {
                strCopy += intSeq[i];
                ++count;
            }

            if ( count == pam ) {
                arrayIndex = stoi(strCopy, nullptr, 4);
                // cout << strCopy<< endl;
                //cout << arrayIndex  << endl;
                kmer[arrayIndex] += 1;
                strCopy = "";
                count = 0;
                i = (i-pam +1);
            }
        }
        else{
            count =0;
            strCopy = "";
        }
    }

    string babe ;
    string kmerOutput;


    for(int j = 0 ; j < arrayLength; ++j) {
        if ( kmer[j] != 0 ) {

            babe = to_base(j,4,pam);

            cout << babe << " "<< kmer[j] << endl;


        }
    }


    delete[] kmer;

}


void FirstLine(const string& p , int& z){
    cout<< "0 " << z << " " << p.length() << endl;}                                  //First Line

void countChar(const string& s, char& a , char& c , char& g , char& t , char& n){

    int aa = 0,gg = 0,tt = 0,cc = 0,nn = 0;

    for (char i : s) {
        if ( i == a ) {
            aa += 1;
        }
        if ( i == c ) {
            cc += 1;
        }
        if ( i == g ) {
            gg += 1;
        }
        if ( i == t ) {
            tt += 1;
        }
        if ( i == n ) {
            nn += 1;
        }
    }

    cout << "1 "<< aa << " " << cc << " " << gg << " "<< tt << " " << nn << endl; // 1 A C G T N

} // Second line


int main(int argc, char* argv[]){

    int k = atoi(argv[2]);

    ifstream myFile(argv[1]);

    string dna_seq;

    const string &dna_seq_copy = dna_seq;

    char a = 'A', c = 'C', g = 'G', t = 'T', n = 'N';

    if(argc == 3 && (k >=2 && k <= 10)) {

        while (myFile.is_open() && myFile.good()) {

            while (getline(myFile, dna_seq)) {

                FirstLine(dna_seq_copy, k);

                countChar(dna_seq_copy, a, c, g, t, n);

                thirdLine(dna_seq_copy,k);

                myFile.close();
            }
        }
    }

    return 0;
};
