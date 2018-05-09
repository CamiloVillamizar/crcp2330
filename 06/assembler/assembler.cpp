#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getComp(string);
string getDest(string);
string getJump(string);

int main()
{
    ifstream inFile;
    inFile.open("MaxL.asm");


    if(!inFile)
        cout << "Error, could not find file" << endl;

    }


    return 0;
}

string getComp(string arg){
    if(arg == "0") return "101010";
    if(arg == "1") return "111111";
    if(arg == "-1") return "111010";
    if(arg == "D") return "001100";
    if(arg == "A") return "110000";//a version
    if(arg == "M") return "110000";//m version
    if(arg == "!D") return "001101";
    if(arg == "!A") return "110001";//a
    if(arg == "!M") return "110001";//m
    if(arg == "-D") return "001111";
    if(arg == "-A") return "110011";//a
    if(arg == "-M") return "110011";//m
    if(arg == "D+1") return "011111";
    if(arg == "A+1") return "110111";//a
    if(arg == "M+1") return "110111";//m
    if(arg == "D-1") return "001110";
    if(arg == "A-1") return "110010";//a
    if(arg == "M-1") return "110010";//m
    if(arg == "D+A") return "000010";//a
    if(arg == "D+M") return "000010";//m
    if(arg == "D-A") return "010011";//a
    if(arg == "D-M") return "010011";//m
    if(arg == "A-D") return "000111";//a
    if(arg == "M-D") return "000111";//m
    if(arg == "D&A") return "000000";//a
    if(arg == "D&M") return "000000";//m
    if(arg == "D|A") return "010101";//a
    if(arg == "D|M") return "010101";//m
    //cout << "INVALID" << endl;
}

string getDest(string arg){
    if(arg == "") return "000";
    if(arg == "M") return "001";
    if(arg == "D") return "010";
    if(arg == "MD") return "011";
    if(arg == "A") return "100";
    if(arg == "AM") return "101";
    if(arg == "AD") return "110";
    if(arg == "AMD") return "111";
    //cout << "INVALID" << endl;
}

string getJump(string arg){
   if(arg == "") return "000";
   if(arg == "JGT") return "001";
   if(arg == "JEQ") return "010";
   if(arg == "JGE") return "011";
   if(arg == "JLT") return "100";
   if(arg == "JNE") return "101";
   if(arg == "JLE") return "110";
   if(arg == "JMP") return "111";
   //cout << "INVALID" << endl;
}
