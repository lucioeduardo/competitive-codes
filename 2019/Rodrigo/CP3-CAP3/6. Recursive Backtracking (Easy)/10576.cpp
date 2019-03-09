#include <bits/stdc++.h>
using namespace std;

int s, d;

int solve(int mask) {
    int current = 0;
            
    for(int k=0; k<4; ++k)
        current += (mask & (1 << k)) ? s : -d;

    for(int k=4; k<12; ++k) {
        current += (mask & (1 << k)) ? s : -d;

        if(current >= 0)
            return 0;

        current -= (mask & (1 << (k - 4))) ? s : -d;
    }

    int answer = 0;
    for(int k=0; k<12; ++k)
        answer += (mask & (1 << k)) ? s : -d;

    return answer;
}

int main() {

    while(cin >> s >> d) {
        int answer = 0;

        for(int i=0; i < (1 << 12); ++i)
            answer = max(answer, solve(i));

        if(answer)
            cout << answer << endl;
        else
            cout << "Deficit" << endl;
        
    }
    return 0;
}