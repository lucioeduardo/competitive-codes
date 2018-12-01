#include <bits/stdc++.h>
using namespace std;

struct rfp{
	string name;
	double price;
	int qtd; 
};

bool comp(rfp a, rfp b){
	if(a.qtd == b.qtd){
		if(a.price == b.price)
			return false;
		return (a.price < b.price);
	}
	return (a.qtd > b.qtd);
}

int main(){
	int n,m;
	int t=0;
	
	bool f = false;
	
	while(scanf("%d %d ",&n, &m) && n){
		if(f) cout<<endl;
		
		string s;
		for(int i=0; i<n; i++){
			getline(cin, s);
		}
		
		rfp res = {"ZZZ",999999,0};
				
		for(int i=0; i<m; i++){
			rfp x;
			
			getline(cin, x.name);
			
			cin>>x.price>>x.qtd;
			getchar();
			
			for(int j=0; j<x.qtd; j++)
				getline(cin,s);
			
			if(comp(x, res))
				res = x;
		}
		
		printf("RFP #%d\n",++t);
		cout << res.name << endl;
		
		f=true;
	}
	
    return 0;
}
