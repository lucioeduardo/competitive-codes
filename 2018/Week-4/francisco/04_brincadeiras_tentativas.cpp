#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0.470s
int main(){

    vector< int > values;
    int n, value;

    while(true){
        cin >> n;

        if(n == 0)
            break;

        for(int i = 0; i < n; i++){
            cin >> value;
            values.push_back(value);
        }

        sort(values.begin(), values.end());

        do{
            for(int i = 0; i < n; i++)
                cout << values[i] << " ";
            cout << endl;
        } while(next_permutation(values.begin(), values.end()));
        cout << endl;

        values.clear();
    }

    return 0;
}