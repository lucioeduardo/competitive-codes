#include <bits/stdc++.h>
#define ul unsigned long
#define bit7 bitset<7>
using namespace std;

int n;
ul number[] = { bit7("1111110").to_ulong(), bit7("0110000").to_ulong(),
                bit7("1101101").to_ulong(), bit7("1111001").to_ulong(),
                bit7("0110011").to_ulong(), bit7("1011011").to_ulong(),
                bit7("1011111").to_ulong(), bit7("1110000").to_ulong(),
                bit7("1111111").to_ulong(), bit7("1111011").to_ulong() };

ul display[15];

bool solve(int ind, int last, int burned) {

    if(ind == n)
        return true;

    for(int i = 0; i < 10; ++i) {

        if((last != -1) && (last - i) != 1)
            continue;

        if(display[ind] & burned)
            continue;
        if(display[ind] & ~number[i])
            continue;
        
        int off = number[i] & ~display[ind];
        if(solve(ind + 1, i, burned | off))
            return true;
    }

    return false;
}

int main() {

    string d;

    while((cin >> n) && n) {
        for(int i=0; i<n; ++i) {
            cin >> d;

            for(int j=0; j<7; ++j)
                d[j] = d[j] == 'Y' ? '1' : '0';

            display[i] = bit7(d).to_ulong();
        }
        
        printf("%s\n", solve(0, -1, 0) ? "MATCH" : "MISMATCH");
    }

    return 0;
}