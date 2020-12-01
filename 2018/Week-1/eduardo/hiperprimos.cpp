/*
 * URI Onli ne Judge | 1602 - Hiperprimos
 * */

#include <cstdio>
#include <vector>
#define MAXN 2000100

using namespace std;

bool is_prime[MAXN];
bool is_hiperprime[MAXN];
int res[MAXN];
vector<int> primes;

void sieve(){
	for(int i=2; i<=MAXN; i++) is_prime[i]=true;
	
	for(int i=2; i*i<=MAXN; i++){
		if(is_prime[i]){
			primes.push_back(i);
			for(int j=2*i; j<=MAXN; j+=i)
				is_prime[j] = false;
		}
	}
	
	for(int i=1000; i<= MAXN; i++)
		if(is_prime[i])
			primes.push_back(i);
}

long long fastpow(long long int a, long long int b){
	long long int res=1;
	
	while(b > 0){
		if(b%2)
			res = res*a;
		a = a*a;
		b /= 2;
		
	}
	
	return res;
}

void fill(){
	for(size_t i=0; i<primes.size(); i++){
	
		for(size_t j=0; j<primes.size(); j++){
			long long int v = fastpow(primes[i], primes[j]-1);
			if(v >= MAXN || v < 0) break;
			is_hiperprime[v] = true; 
		}

	}
}



int main(){
	int n;
	
	sieve();
	fill();
	
	res[2]=1;
	for(int i=3; i<MAXN; i++){
		res[i] = res[i-1];
		if(is_hiperprime[i])
			res[i]++;
	}	
	
		
	while(scanf("%d", &n) != EOF){
		printf("%d\n",res[n]);
	}
	
	
	
	
	return 0;	
}

