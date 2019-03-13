#include <bits/stdc++.h>
using namespace std;

int n;
string display[15];
string key[15];
unordered_map<string, int> number;


bool solve(int ind, int last, string turnOff) {

    if(ind == n) {
        for(int i=1; i<n; ++i) {
            if((number[display[i - 1]] - number[display[i]]) != 1)
                return false;
        }

        return true;
    }

    for(auto &num: number) {

        bool testNumber = true;

        for(int i=0; i<7; ++i) {
            if((display[ind][i] == 'Y' && num.first[i] == 'N')) {
                testNumber = false;
                break;
            }
        }

        if(testNumber) {
            testNumber = false;
            for(int i=0; i<7; ++i) {
                if(num.first[i] != turnOff[i])
                    testNumber = true;
            }
        }

        if(testNumber && ((last == -1) || ((last != -1) && ((last-num.second) == 1)) )) {
            string recover = display[ind];
            display[ind] = num.first;
            string off = turnOff;

            for(int i=0; i<7; ++i) {
                if(num.first[i] != recover[i])
                    off[i] = 'Y';
            }

            if(solve(ind + 1, num.second, off))
                return true;

            display[ind] = recover;
        }
    }

    return false;
}

int main() {
    
    number["YYYYYYN"] = 0; number["NYYNNNN"] = 1;
    number["YYNYYNY"] = 2; number["YYYYNNY"] = 3;
    number["NYYNNYY"] = 4; number["YNYYNYY"] = 5;
    number["YNYYYYY"] = 6; number["YYYNNNN"] = 7;
    number["YYYYYYY"] = 8; number["YYYYNYY"] = 9;
    
    while((cin >> n) && n) {
        for(int i=0; i<n; ++i)
            cin >> display[i];
        
        printf("%s\n", solve(0, -1, "NNNNNNN") ? "MATCH" : "MISMATCH");
    }
    return 0;
}