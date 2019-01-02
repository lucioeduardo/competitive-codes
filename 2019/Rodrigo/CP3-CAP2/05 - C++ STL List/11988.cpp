// 11988 - Broken Keyboard

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    while(cin >> str)
    {
        list<char> output;
        list<char> ::iterator it;
        it = output.begin();

        for(int i=0; str[i]; ++i)
        {
            if(str[i] == '[')
                it = output.begin();
            else if(str[i] == ']')
                it = output.end();
            else
                output.insert(it, str[i]);
        }
        
        for(auto &e : output)
            cout << e;
        cout << endl;
    }
    return 0;
}