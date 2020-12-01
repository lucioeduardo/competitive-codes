/** Distinct Primes **/
#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int n = 2700;
    int was[n];

    memset(was, 0, sizeof(was));

    for(int i = 2; i <= n; i++){
        if(was[i] == 0)
            for(int j = i*2; j <= n; j += i)
                was[j]++;
    }

    int arr[1001];
    int c = 1;
    for(int k = 30; k < n && c < 1001; k++){
        if(was[k] >= 3)
            arr[c++] = k;
    }

    int t;
    int r;
    cin >> t;
    while(t--){
        cin >> r;
        cout << arr[r] << endl;
    }

    return 0;
}