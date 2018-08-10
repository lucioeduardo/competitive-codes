#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n;
    vector< int > v;

    cin >> n;

    int milk;
    while(n--){
        cin >> milk;
        v.push_back(milk);
    }

    sort(v.begin(), v.end());

    cout << v[(v.size()/2)] << endl;

    return 0;
}