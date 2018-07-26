/** A. Noldbach problem **/
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

bool isPrime(int n);

int main(){

    int n, k;
    cin >> n;

    int var[n];
    memset(var, 1, sizeof(var));
    var[0] = var[1] = 0;

    int arr[n];
    int c = 0;
    for(int i = 2; i <= n; i++)
        if(var[i]){
            arr[c++] = i;
            for(int j = i*i; j <= n; j += i)
                var[j] = 0;
        }

    int count = 0;
    for(int i = 0; i < c-1; i++)
        if(isPrime(arr[i]+arr[i+1]+1) && arr[i]+arr[i+1]+1 <= n)
            count++;

    cin >> k; 
    if(k <= count)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0; 
}

bool isPrime(int n){
    int sqrtint = sqrt(n)+1;
    int i;
    for(i = 2; i < sqrtint; i++)
        if(n % i == 0)
            return false;
    return true;
}