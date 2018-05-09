#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string toBinary(int);
string getComp(string);
string getDest(string);
string getJump(string);

int main(int argc, char* argv[])
{
    ifstream inFile;
    inFile.open(argv[1]);


    if(!inFile)
        cout << "Error, could not find file" << endl;

    bool aCom;


    string input;
    getline(inFile, input);


    while(input[0] != '@')
        inFile >> input;


    while(!inFile.eof()){

        if(input[0] == '@')
            aCom = true;
        else
            aCom = false;



        //cout << input;

        if(aCom == true){
            //cout << "; A command" << endl;
            stringstream num(input.substr(1, input.length() - 1));//turns the string into an int

            int temp;
            num >> temp;

            string bin = toBinary(temp);

            cout << bin << endl;//binary number
        }
        else{
            //cout << "; C command" << endl;
            string a, comp, dest, jump;

            size_t eqIdx = input.find("=");
            size_t scIdx = input.find(";");

            if(eqIdx > input.size()){
                if(input.find("M") > input.size())
                    a = "0";
                else
                    a = "1";
                dest = "";

                comp = input[0];
                jump = input.substr(2, input.size());
                comp = getComp(comp);
                dest = getDest(dest);
                jump = getJump(jump);

            } else {
                if(input.find("M") > input.size())
                    a = "0";
                else
                    a = "1";
                jump = "";

                dest = input[0];
                comp = input.substr(2, input.size());
                dest = getDest(dest);
                comp = getComp(comp);
                jump = getJump(jump);
            }


            cout << "111" << a << comp << dest << jump << endl;

        }

        inFile >> input;


    }


    return 0;
}

string toBinary(int n){
    string r;
    while(n != 0){
        string temp;
        if(n % 2 == 0)
            temp = "0";
        else
            temp = "1";
        temp += r;

        r = temp;

        n /= 2;
    }

    while(r.length() != 16)
        r = "0" + r;

    return r;
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
