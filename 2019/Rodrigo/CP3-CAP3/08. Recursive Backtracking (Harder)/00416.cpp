#include <bits/stdc++.h>
using namespace std;

int n;
string display[15];
unordered_map<string, int> number;


bool solve(int ind, int last, int burned) {

    if(ind == n)
        return true;

    for(auto &num: number) {

        if((last != -1) && (last - num.second) != 1)
            continue;

        bool testNumber = true;
        int off = 0;

        for(int i=0; i<7 && testNumber; ++i) {

            if(display[ind][i] == 'Y' && (burned & (1 << i)))
                testNumber = false;

            else if(display[ind][i] == 'Y' && num.first[i] == 'N')
                testNumber = false;

            else if(num.first[i] == 'Y' && display[ind][i] == 'N')
                off |= (1 << i);
            
        }
        
        if(testNumber) {
            if(solve(ind + 1, num.second, burned | off))
                return true;
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
        
        printf("%s\n", solve(0, -1, 0) ? "MATCH" : "MISMATCH");
    }

    return 0;
}