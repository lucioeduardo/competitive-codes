#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;

    while(t--) {
        int target; cin >> target;
        int n; cin >> n;
        int bars[n];
        string answer = "NO";

        for(int i=0; i<n; ++i)
            cin >> bars[i];

        for(int mask=0; mask<=(1<<n) - 1 && answer == "NO"; ++mask) {
            int current = 0;

            for(int bit=0; bit<n && current < target; ++bit)
                if(mask & (1 << bit))
                    current += bars[bit];

            if(current == target)
                answer = "YES";
        }
        
        cout << answer << endl;
    }
    return 0; 
}