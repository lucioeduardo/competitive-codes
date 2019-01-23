#include <bits/stdc++.h>
using namespace std;

int n, n_comb=0, n_perm=0;

string mult_char(int q, char c){
	string res = "";
	while(q--) res += c;
	return res;
}

void calc(int a, int b, int c){
	if(a + b + c == n){
		n_comb++;

		if(a == b && b == c)
			n_perm++;
		else if(a == b || b == c || a == c)
			n_perm += 3;
		else
			n_perm += 6;
	}
}

int main(){
	vector<int> v;

	for(int i=1; i<=20; i++){
		v.push_back(i);
		if(i>10)v.push_back(2*i);
		if(i % 2 == 0 && 3*i <= 40) continue;
		
		if(i>6) v.push_back(3*i);
	}

	v.push_back(50);
	v.push_back(0);

	sort(v.begin(), v.end());

	string sep = mult_char(70,'*');

	while(scanf("%d",&n) && n > 0){
		n_comb = n_perm = 0;

		int t = v.size();

		for(int i=0; i< t; i++){
			for(int j=i; j< t; j++){
				for(int k=j; k< t; k++){
					calc(v[i],v[j],v[k]);
				}
			}
		}

		if(n_comb == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		else{
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,n_comb);
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,n_perm);
		}
		cout<<sep<<endl;
	}

	cout << "END OF OUTPUT\n";

	return 0;
}
