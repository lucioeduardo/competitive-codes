#include <bits/stdc++.h>

using namespace std;

int main(){

    string s, ts;

    while(true){

        cin >> s;

        if(s == "#") break;

        ts = s;
        sort(ts.begin(), ts.end());

        next_permutation(s.begin(), s.end());

        if(s == ts)
            cout << "No Successor" << endl;
        else
            cout << s << endl;

    }

    return 0;
}