#include <bits/stdc++.h>
#define MAXN 10010
using namespace std;

string maker[MAXN];
int L[MAXN], H[MAXN];

string solve(int d, int q) {
    string answer = "UNDETERMINED";

    for(int i=0; i<d; ++i) {
        if(q >= L[i] && q <= H[i]) {
            if(answer == "UNDETERMINED")
                answer = maker[i];
            else return "UNDETERMINED";
        }
    }

    return answer;
}

int main()
{
    int t; cin >> t;

    for(int qt = 0; qt < t; ++qt) {
        int d; cin >> d;
        
        if(qt)
            cout << endl;

        for(int i=0; i<d; ++i)
            cin >> maker[i] >> L[i] >> H[i];

        int Q; cin >> Q;

        while(Q--) {
            int q; cin >> q;
            cout << solve(d, q) << endl;
        }
    }
    return 0;
}
