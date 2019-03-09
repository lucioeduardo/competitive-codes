#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll s,d;
ll values[13];

ll solve(ll month, ll sum){
	//prllf("%d\n",sum);
	if(month > 5 && sum > 0)
		return -999999999999;
	if(month > 12)
		return 0;
	
	if(month > 5)
		sum -= values[month-5];
	
	values[month] = -d;
	ll def = -d + solve(month+1, sum-d);

	values[month] = s;
	ll sup = s + solve(month+1, sum+s);

	return max(def,sup);
}

int main(){

	while(scanf("%d %d", &s, &d) != EOF){
		ll res = solve(1,0);

		if(res < 0) printf("Deficit\n");
		else printf("%d\n",solve(1,0));
	}

	return 0;
}
