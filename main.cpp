#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
using namespace std;


//Variables

const int arraySize = 100;
int gateAND = 0;
int gateOR = 0;
int gateNOT = 0;
int gateXOR = 0;
int gateNAND = 0;
int gateNOR = 0;
int varCount = 0;
//int finalGatesResult = 0;

string splittedInput[arraySize] = {};
string userInput;
string foundedVar[arraySize] = {};

bool varMsgShown = false;
bool varFounded = false;

///////////

bool andFunc(bool firstInp, bool secondInp) {
    gateAND++;
    return (firstInp && secondInp);
}
bool orFunc(bool firstInp, bool secondInp) {
    gateOR++;
    return (firstInp || secondInp);
}
bool notFunc(bool firstInp) {
    gateNOT++;
    return !firstInp;

}
bool xorFunc(bool firstInp, bool secondInp) {
    gateXOR++;
    if (firstInp != secondInp) {
        return true;
    }
    else {
        return false;
    }
}
bool nandFunc(bool firstInp, bool secondInp) {
    gateNAND++;
    return !(firstInp && secondInp);

}
bool norFunc(bool firstInp, bool secondInp) {
    gateNOR++;
    return !(firstInp || secondInp);

}

void fixArray() {
    for (int i = 0; i < arraySize - 20; i++) {
        for (int j = i; j > 0; j--) {
            if (splittedInput[j] == "") {
                splittedInput[j] = splittedInput[j + 1];
                splittedInput[j + 1] = "";
            }
        }
    }

}

void errorHadling() {
    for (int i = 0; i < arraySize; i++) {
        if (splittedInput[i] == "e") {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
    }
}
bool stringToBoolean(string input) {
    if (input == "0") {
        return false;
    }
    else {
        return true;
    }
}
string booleanToString(bool input) {
    if (input == false) {
        return "0";
    }
    else {
        return "1";
    }
}

void splitString() {
    char text[500];
    strcpy(text, userInput.c_str());
    char str[500];
    int index = 0;
    int arrind = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        while (text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' || text[i] == '0' || text[i] == '1' || text[i] == 'e' || text[i] > '0')
        {
            str[index++] = text[i];
            i++;
        }
        str[index] = '\0';

            string s(str);
            splittedInput[arrind] = s;
            arrind++;
        
        index = 0;

    }
    fixArray();
}


bool isSingleAlphabet(const string& s) {
    return s.size() == 1 && isalpha(s[0]);
}

int countUniqueStrings(string arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (!isSingleAlphabet(arr[i])) {
            continue;
        }
        if (arr[i] == "e") {
            continue;
        }
        bool isUnique = true;
        for (int j = 0; j < i; ++j) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            ++count;
        }
    }

    return count;
}
bool varCheckerDone = true;
string userVarEdit;
void varHandle(string variableSent) {
    varCount = countUniqueStrings(splittedInput, arraySize);
    if (varMsgShown == false) {
        cout << varCount << " varaibles are missing please enter them in separate lines" << endl;
        varMsgShown = true;
    }

    for (int i = 0; i < varCount; i++) {
        cin >> userVarEdit;
        string s(1, userVarEdit[0]);
        string se(1, userVarEdit[2]);
        for (int i = 0; i < arraySize; i++) {
            if (splittedInput[i] == s) {
                splittedInput[i] = se;
            }
        }
    }
    
}
void varChecker() {
    for(int i = 0; i < arraySize; i++){
        if (splittedInput[i] == "a" ||
            splittedInput[i] == "b" ||
            splittedInput[i] == "c" ||
            splittedInput[i] == "d" ||
            splittedInput[i] == "f" ||
            splittedInput[i] == "g" ||
            splittedInput[i] == "h" ||
            splittedInput[i] == "j" ||
            splittedInput[i] == "k" ||
            splittedInput[i] == "l" ||
            splittedInput[i] == "m" ||
            splittedInput[i] == "n" ||
            splittedInput[i] == "o" ||
            splittedInput[i] == "p" ||
            splittedInput[i] == "q" ||
            splittedInput[i] == "r" ||
            splittedInput[i] == "s" ||
            splittedInput[i] == "t" ||
            splittedInput[i] == "u" ||
            splittedInput[i] == "v" ||
            splittedInput[i] == "w" ||
            splittedInput[i] == "x" ||
            splittedInput[i] == "y" ||
            splittedInput[i] == "z" ||
            splittedInput[i] == "A" ||
            splittedInput[i] == "B" ||
            splittedInput[i] == "C" ||
            splittedInput[i] == "D" ||
            splittedInput[i] == "F" ||
            splittedInput[i] == "G" ||
            splittedInput[i] == "H" ||
            splittedInput[i] == "I" ||
            splittedInput[i] == "J" ||
            splittedInput[i] == "K" ||
            splittedInput[i] == "L" ||
            splittedInput[i] == "M" ||
            splittedInput[i] == "N" ||
            splittedInput[i] == "O" ||
            splittedInput[i] == "P" ||
            splittedInput[i] == "Q" ||
            splittedInput[i] == "R" ||
            splittedInput[i] == "S" ||
            splittedInput[i] == "T" ||
            splittedInput[i] == "U" ||
            splittedInput[i] == "V" ||
            splittedInput[i] == "W" ||
            splittedInput[i] == "X" ||
            splittedInput[i] == "Y" ||
            splittedInput[i] == "Z") {

            varHandle(splittedInput[i]);
            if (i == 0) {
                varCheckerDone = true;
                varHandle(splittedInput[i]);
            }

       }

    }
}

int solveGate(string gateName, int arrayPosition) {
    if(gateName == "AND"){

        if (splittedInput[arrayPosition + 1] == "0" || splittedInput[arrayPosition + 1] == "1" && splittedInput[arrayPosition + 2] == "0" || splittedInput[arrayPosition + 2] == "1") {
            splittedInput[arrayPosition] = booleanToString(andFunc(stringToBoolean(splittedInput[arrayPosition + 1]), stringToBoolean(splittedInput[arrayPosition + 2])));
            splittedInput[arrayPosition + 1] = "";
            splittedInput[arrayPosition + 2] = "";

            if (splittedInput[arrayPosition + 3] == "e") {
                splittedInput[arrayPosition + 3] = "";
            }
        }
        else {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
        fixArray();
    }
    else if (gateName == "OR") {

        if (splittedInput[arrayPosition + 1] == "0" || splittedInput[arrayPosition + 1] == "1" && splittedInput[arrayPosition + 2] == "0" || splittedInput[arrayPosition + 2] == "1") {
            splittedInput[arrayPosition] = booleanToString(orFunc(stringToBoolean(splittedInput[arrayPosition + 1]), stringToBoolean(splittedInput[arrayPosition + 2])));
            splittedInput[arrayPosition + 1] = "";
            splittedInput[arrayPosition + 2] = "";

            if (splittedInput[arrayPosition + 3] == "e") {
                splittedInput[arrayPosition + 3] = "";
            }
        }
        else {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
        fixArray();

    }
    else if (gateName == "NOT") {

        if (splittedInput[arrayPosition + 1] == "0" || splittedInput[arrayPosition + 1] == "1") {
            splittedInput[arrayPosition] = booleanToString(notFunc(stringToBoolean(splittedInput[arrayPosition + 1])));
            splittedInput[arrayPosition + 1] = "";

            if (splittedInput[arrayPosition + 2] == "e") {
                splittedInput[arrayPosition + 2] = "";
            }
        }
        else {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
        fixArray();
    }
    else if (gateName == "XOR") {

        if ((splittedInput[arrayPosition + 1] == "0" || splittedInput[arrayPosition + 1] == "1") && (splittedInput[arrayPosition + 2] == "0" || splittedInput[arrayPosition + 2] == "1")) {
            splittedInput[arrayPosition] = booleanToString(xorFunc(stringToBoolean(splittedInput[arrayPosition + 1]), stringToBoolean(splittedInput[arrayPosition + 2])));
            splittedInput[arrayPosition + 1] = "";
            splittedInput[arrayPosition + 2] = "";

            if (splittedInput[arrayPosition + 3] == "e") {
                splittedInput[arrayPosition + 3] = "";
            }
        }
        else {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
        fixArray();
    }
    else if (gateName == "NAND") {

        if ((splittedInput[arrayPosition + 1] == "0" || splittedInput[arrayPosition + 1] == "1") && (splittedInput[arrayPosition + 2] == "0" || splittedInput[arrayPosition + 2] == "1")) {
            splittedInput[arrayPosition] = booleanToString(nandFunc(stringToBoolean(splittedInput[arrayPosition + 1]), stringToBoolean(splittedInput[arrayPosition + 2])));
            splittedInput[arrayPosition + 1] = "";
            splittedInput[arrayPosition + 2] = "";

            if (splittedInput[arrayPosition + 3] == "e") {
                splittedInput[arrayPosition + 3] = "";
            }
        }
        else {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
        fixArray();
    }
    else if (gateName == "NOR") {

        if ((splittedInput[arrayPosition + 1] == "0" || splittedInput[arrayPosition + 1] == "1") && (splittedInput[arrayPosition + 2] == "0" || splittedInput[arrayPosition + 2] == "1")) {
            splittedInput[arrayPosition] = booleanToString(norFunc(stringToBoolean(splittedInput[arrayPosition + 1]), stringToBoolean(splittedInput[arrayPosition + 2])));
            splittedInput[arrayPosition + 1] = "";
            splittedInput[arrayPosition + 2] = "";

            if (splittedInput[arrayPosition + 3] == "e") {
                splittedInput[arrayPosition + 3] = "";
            }
        }
        else {
            cout << "result : BAD input : missing input number";
            exit(0);
        }
        fixArray();
    }
    else if (gateName == "e") {
    }
    else if (gateName == "1") {
    }
    else if (gateName == "0") {
    }
    else if (gateName == "") {
    }
    else {
        cout << "Wrong Logic Circuit Description";
        exit(0);
    }
    return 0;
}

int main()
{
    getline(cin, userInput);
    splitString();
    varChecker();

    for (int i = arraySize - 1; i >= 0; i--) {
        solveGate(splittedInput[i], i);
    }

    //errorHadling();



    cout << "AND gates : " << gateAND << endl;
    cout << "OR gates : " << gateOR << endl;
    cout << "NOT gates : " << gateNOT << endl;
    cout << "XOR gates : " << gateXOR << endl;
    cout << "NAND gates : " << gateNAND << endl;
    cout << "NOR gates : " << gateNOR << endl;
    cout << "result : " << splittedInput[0] << endl;

    return 0;
}

