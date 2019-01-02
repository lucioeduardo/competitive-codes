// 732 - Anagrams by Stack

#include <bits/stdc++.h>
using namespace std;

string a, b;

void solve(int index, string stk, string permutation, string output)
{
    int size = stk.size();

    if(index == a.size() && size == 0)
    {
        if(permutation == b)
            cout << output.substr(0, output.size() - 1) << endl;
        return;
    }

    if(index < a.size())
        solve(index + 1, stk + a[index], permutation, output + "i ");

    if(size > 0) {
        if(stk[size - 1] == b[permutation.size()])
            solve(index, stk.substr(0, size - 1), permutation + stk[size - 1], output + "o ");
    }
}

int main()
{
    while(cin >> a >> b) {
        cout << "[" << endl;
        if(a.size() == b.size())
            solve(0, "", "", "");
        cout << "]" << endl;
    }
    return 0;
}