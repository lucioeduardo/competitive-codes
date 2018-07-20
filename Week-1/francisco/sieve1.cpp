/**
 (*) A list of prime numbers.
 Given a range of integers by its lower and upper limit, construct a list of all prime numbers in that range.
 **/
#include <iostream>
#include <vector>

using namespace std;

vector<char> sieve(int n);

int main(){
    int lower = 10;
    int upper = 100;
    
    vector<char> prime = sieve(upper);

    for(int i = lower; i <= upper; i++)
        if(prime[i]) cout << i << " ";
    cout << endl;
    
    return 0;
}

vector<char> sieve(int n){
    vector<char> prime(n+1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= n; i++)
        if(prime[i])
            if(i * 1ll * i <= n)
                for(int j = i * i; j <= n; j += i)
                    prime[j] = false;
    return prime;
}