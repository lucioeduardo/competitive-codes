// 1062 - Containers

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int test = 0;

    while((cin >> s) && s != "end")
    {
        string p;
        for(auto &e : s) {
            auto it = lower_bound(p.begin(), p.end(), e);

            if(it == p.end())
                p.push_back(e);
            else
                p[it - p.begin()] = e;
        }

        cout << "Case " << ++test << ": " << p.size() << endl;
    }

    return 0;
}