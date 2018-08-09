#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 0.02s
int main(){

    int t;
    string a, b, ra;

    cin >> t;

    while(t--){
        cin >> a >> b;
        
        ra = a;
        b += b;
        
        reverse(ra.begin(), ra.end());

        if(b.find(a) != string::npos || b.find(ra) != string::npos)
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}