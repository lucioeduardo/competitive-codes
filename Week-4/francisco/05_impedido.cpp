#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0.00s
int main(){

    int a, d, vala, vald;
    vector< int > v1,v2;

    bool res;
    int i;
    while(true){
        res = true;
        cin >> a >> d;

        if(a == 0 && d == 0){
            break;
        }

        for(i = 0; i < a; i++){
            cin >> vala;
            v1.push_back(vala);
        }

        for(i = 0; i < d; i++){
            cin >> vald;
            v2.push_back(vald);
        }

        sort(v2.begin(), v2.end());

        for(i = 0; i < a; i++){
            if(v1[i] < v2[1]){
                res = false;
                break;
            }
        }

        v1.clear();
        v2.clear();

        if(!res)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}