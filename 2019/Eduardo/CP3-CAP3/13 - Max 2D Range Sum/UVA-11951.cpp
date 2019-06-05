#include <bits/stdc++.h>
#define MAXN 110
#define ll long long
#define pii pair<ll,ll>

using namespace std;

ll mapa[MAXN][MAXN];
ll n,m,k;

pii kadane(ll vet[]){
	ll res = 0, res_sum=9999999;
	ll sum = 0, act = 0;

	for(int j=0;j<n;j++){
		sum=act=0;
		for(int i=j;i<n;i++){
			if(sum + vet[i] > k)
				sum=act=0;

			sum += vet[i];
			act++;
			
			if(act >= res && sum <= k){
				if(act == res)
					res_sum = min(res_sum,sum);
				else
					res_sum = sum;

				res = act;

				
			}
			
		}
	}

	return {res,res_sum};
}

pii max_pair(pii a, pii b){
	if(a.first != b.first)
		return a.first > b.first ? a : b;
	return a.second < b.second ? a : b;
}

pii max2d(){
	pii res = {0,0};
	ll temp[n];
	for(int i=0; i<m; i++){
		memset(temp,0,sizeof(temp));

		for(int j=i; j<m; j++){

			for(int k=0; k<n; k++){
				temp[k] += mapa[k][j];
			}
			
			pii val = kadane(temp);
			val.first *= (j-i)+1;
			
			res = max_pair(res, val);
		}
	}

	return res;
}

int main(){
	int t;

	scanf("%d",&t);


	for(int c=1;c<=t;c++){
		

		scanf("%lld %lld %lld",&n,&m,&k);

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%lld",&mapa[i][j]);
			}
		}

		pii res = max2d();
		printf("Case #%d: %lld %lld\n", c, res.first, res.second);
	}

	return 0;
}
