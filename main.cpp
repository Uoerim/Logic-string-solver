#include <iostream>
#include <string>
using namespace std;

//Boolean functions
bool andFunc(bool firstInp, bool secondInp) {
    return (firstInp && secondInp);
}
bool orFunc(bool firstInp, bool secondInp) {
    return (firstInp || secondInp);
}
bool notFunc(bool firstInp) {
    return !firstInp;

}
bool xorFunc(bool firstInp, bool secondInp) {
    if (firstInp != secondInp) {
        return true;
    }
    else {
        return false;
    }
}
bool nandFunc(bool firstInp, bool secondInp) {
    return !(firstInp && secondInp);

}
bool norFunc(bool firstInp, bool secondInp) {
    return !(firstInp || secondInp);

}

//Global Array (To get fixed)
const int arraySize = 20;
string splittedInput[arraySize] = {};

void fixArray() {
    for (int i = arraySize - 1; i > 0; i--) {
        if (splittedInput[i - 1] == "") {
            splittedInput[i - 1] = splittedInput[i];
            splittedInput[i] = "";
        }
    }
}

int main()
{
    //input
    string userInput;

    //Memory
    //int detectedGatesIDS[arraySize] = {};
    //int detectedStopIDS[arraySize] = {};
    //bool inpOne = false;
    //bool inpTwo = false;

    //Counters
    int gateAND = 0;
    int gateOR = 0;
    int gateNOT = 0;
    int gateXOR = 0;
    int gateNAND = 0;
    int gateNOR = 0;
    int finalGatesResult = 0;
    //bool resultInBoolean = false;


    //input reciever and splitter
    getline(cin, userInput);

    size_t startPos = 0, foundPos;
    int arrPos = 0;
    do {
        foundPos = userInput.find(' ', startPos);
        if (userInput.substr(startPos, foundPos - startPos) == "e") {
        }
        else {
            splittedInput[arrPos] = userInput.substr(startPos, foundPos - startPos);
            arrPos++;
        }
        startPos = foundPos + 1;


    } while (foundPos != string::npos);

    /////////////////////////                   MAIN                   /////////////////////////

    //Counter
    for (int i = 0; i < arraySize; i++) {
        if (splittedInput[i] == "AND") {
            gateAND++;
        }
        else if (splittedInput[i] == "OR") {
            gateOR++;
        }
        else if (splittedInput[i] == "NOT") {
            gateNOT++;
        }
        else if (splittedInput[i] == "XOR") {
            gateXOR++;
        }
        else if (splittedInput[i] == "NAND") {
            gateNAND++;
        }
        else if (splittedInput[i] == "NOR") {
            gateNOR++;
        }
    }
    /////////

    //Ids Dectors
    //int gatesIDs = 0, eIDs = 0;
    //for (int i = 0; i < arraySize; i++) {
    //    if (splittedInput[i] == "AND") {
    //        detectedGatesIDS[gatesIDs] = i;
    //        gatesIDs++;
    //    }
    //    else if (splittedInput[i] == "OR") {
    //        detectedGatesIDS[gatesIDs] = i;
    //        gatesIDs++;
    //    }
    //    else if (splittedInput[i] == "NOT") {
    //        detectedGatesIDS[gatesIDs] = i;
    //        gatesIDs++;
    //    }
    //    else if (splittedInput[i] == "XOR") {
    //        detectedGatesIDS[gatesIDs] = i;
    //        gatesIDs++;
    //    }
    //    else if (splittedInput[i] == "NAND") {
    //        detectedGatesIDS[gatesIDs] = i;
    //        gatesIDs++;
    //    }
    //    else if (splittedInput[i] == "NOR") {
    //        detectedGatesIDS[gatesIDs] = i;
    //        gatesIDs++;
    //    }
    //    else if (splittedInput[i] == "e") {
    //        detectedStopIDS[eIDs] = i;
    //        eIDs++;
    //    }
    //}
    /////////////


    //Error handling
    for (int i = 0; i < arraySize; i++) {
        if (splittedInput[i] == "AND") {
        }
        else if (splittedInput[i] == "OR") {
        }
        else if (splittedInput[i] == "NOT") {
        }
        else if (splittedInput[i] == "XOR") {
        }
        else if (splittedInput[i] == "NAND") {
        }
        else if (splittedInput[i] == "NOR") {
        }
        else if (splittedInput[i] == "1") {
        }
        else if (splittedInput[i] == "0") {
        }
        else if (splittedInput[i] == "e") {
        }
        else if (splittedInput[i] == "") {
        }
        else {
            cout << "Wrong Logic Circuit Description";
            return 0;
        }
    }
    ///////////////
    
    //Logic Handling

    for (int i = arraySize; i >= 0; i--) {
        if (splittedInput[i] == "AND") {
            bool andInp1 = false;
            bool andInp2 = false;
            splittedInput[i + 1] == "0" ? andInp1 = 0 : andInp1 = 1;
            splittedInput[i + 2] == "0" ? andInp2 = 0 : andInp2 = 1;

            if (andFunc(andInp1, andInp2) == false) {
                splittedInput[i] = "0";

            }
            else {
                splittedInput[i] = "1";
            }
            splittedInput[i + 1] = "";
            splittedInput[i + 2] = "";
            fixArray();
        }
        else if (splittedInput[i] == "OR") {
            bool orInp1 = false;
            bool orInp2 = false;
            splittedInput[i + 1] == "0" ? orInp1 = 0 : orInp1 = 1;
            splittedInput[i + 2] == "0" ? orInp2 = 0 : orInp2 = 1;

            if (orFunc(orInp1, orInp2) == false) {
                splittedInput[i] = "0";

            }
            else {
                splittedInput[i] = "1";
            }
            splittedInput[i + 1] = "";
            splittedInput[i + 2] = "";
            fixArray();
        }
        else if (splittedInput[i] == "NOT") {
            bool notInp1 = false;
            splittedInput[i + 1] == "0" ? notInp1 = 0 : notInp1 = 1;
            if (notFunc(notInp1) == false) {
                splittedInput[i] = "0";
            }
            else {
                splittedInput[i] = "1";
            }
            splittedInput[i + 1] = "";
            fixArray();
        }
        else if (splittedInput[i] == "XOR") {
            bool xorInp1 = false;
            bool xorInp2 = false;
            splittedInput[i + 1] == "0" ? xorInp1 = 0 : xorInp1 = 1;
            splittedInput[i + 2] == "0" ? xorInp2 = 0 : xorInp2 = 1;

            if (xorFunc(xorInp1, xorInp2) == false) {
                splittedInput[i] = "0";

            }
            else {
                splittedInput[i] = "1";
            }
            splittedInput[i + 1] = "";
            splittedInput[i + 2] = "";
            fixArray();
        }
        else if (splittedInput[i] == "NAND") {
            bool nandInp1 = false;
            bool nandInp2 = false;
            splittedInput[i + 1] == "0" ? nandInp1 = 0 : nandInp1 = 1;
            splittedInput[i + 2] == "0" ? nandInp2 = 0 : nandInp2 = 1;

            if (nandFunc(nandInp1, nandInp2) == false) {
                splittedInput[i] = "0";

            }
            else {
                splittedInput[i] = "1";
            }
            splittedInput[i + 1] = "";
            splittedInput[i + 2] = "";
            fixArray();
        }
        else if (splittedInput[i] == "NOR") {
            bool norInp1 = false;
            bool norInp2 = false;
            splittedInput[i + 1] == "0" ? norInp1 = 0 : norInp1 = 1;
            splittedInput[i + 2] == "0" ? norInp2 = 0 : norInp2 = 1;

            if (norFunc(norInp1, norInp2) == false) {
                splittedInput[i] = "0";

            }
            else {
                splittedInput[i] = "1";
            }
            splittedInput[i + 1] = "";
            splittedInput[i + 2] = "";
            fixArray();
        }
    }
    if (splittedInput[0] == "0") {
        finalGatesResult = 0;
    }
    else {
        finalGatesResult = 1;
    }

    ////////////////


    ////////////////////////////////////////////////////////////////////////////////////////////
    // 
    //Outputs
    //cout << "{ ";
    //for (int i = 0; i < arraySize; i++) {
    //    cout << splittedInput[i] << ", ";
    //}
    //cout << " }" << endl;
    //cout << "-----------------------------------------------" << endl;
    cout << "AND gates : " << gateAND << endl;
    cout << "OR gates : " << gateOR << endl;
    cout << "NOT gates : " << gateNOT << endl;
    cout << "XOR gates : " << gateXOR << endl;
    cout << "NAND gates : " << gateNAND << endl;
    cout << "NOR gates : " << gateNOR << endl;
    cout << "result : " << finalGatesResult << endl;

}

