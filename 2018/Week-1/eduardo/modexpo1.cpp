#include <cstdio>
#include <iostream>
#define M 1000000007
using namespace std;

long long int modexp10[100100];

long long int powmod(long long a, long long b){
	if(b == 0) return 1;
	
	a %= M;
	long long res=1;
	
	while(b > 0){
		if(b%2){
			res = (res*a)%M;
		}
		
		a = (a*a)%M;
		b/=2;
	}	
	
	return res;
}

void fill(){
	modexp10[0] = 1;
	for(int i=1; i<=100000; i++){
		modexp10[i] = (modexp10[i-1]*10) % (M-1);
	}
}


long long powmod10(long long a, long long base, long long exp){
	a %= M;
	a = powmod(a,base);
	
	if(base == 0) return 1;
	
	return powmod(a, modexp10[exp]);
}


long long int toint(string s){
	long long int res=0;
	
	for(size_t i=0;i<s.length();i++){
		int expo = s.length()-(i+1);
		
		int v = (s[i] - '0');
		res += v*powmod(10,expo);
		res %= M;
	}
	
	return res;
}


long long int solve(long long a, string s){
	long long int res=1;
	
	for(size_t i=0;i<s.length();i++){
		int expo = s.length()-(i+1);
		int base = (s[i] - '0');
				
		res *= (powmod10(a,base,expo) % M);
		
		res %= M;
	}
	
	return res;
}

int main(){
	int n;
	string a,b;
		
	scanf("%d",&n);
	
	fill();
	
	for(int i=0;i<n;i++){
		cin>>a>>b;
		long long int x = toint(a);
		
		printf("%lld\n",solve(x,b));
	}
	
	
	return 0;
}

int factorial(int n){
	if(n == 0) return 1;
	return n*factorial(n-1);
}
