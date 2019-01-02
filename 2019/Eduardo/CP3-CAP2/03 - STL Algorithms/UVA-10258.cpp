#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

int c[MAXN][10], qtd[MAXN], pen[MAXN];
bool part[MAXN];
vector<int> res;

bool compare(int a, int b){
	if(qtd[a] == qtd[b]){
		if(pen[a] == pen[b])
			return a<b;
		return pen[a] < pen[b];
	}
	return qtd[a] > qtd[b];
}

int main(){
	int t;
	
	scanf("%d ",&t);
	
	for(int i=0; i<t; i++){
		if(i > 0) printf("\n");
		
		res.clear();
		int cont,p,t;
		char l;
		
		for(int i=0; i<MAXN; i++){
			qtd[i] = pen[i] = 0;
			part[i] = false;
			for(int j=0; j<10; j++)
				c[i][j] = 0;
		}
		
		
		string s;
		while(getline(cin,s)){
			if(s.empty()) break;
			sscanf(s.c_str(), "%d %d %d %c",&cont,&p,&t,&l);
			
			part[cont] = true;
			
			if(l == 'I' && c[cont][p] != -1)
				c[cont][p]++;
			else if(l == 'C' && c[cont][p] != -1){
				qtd[cont]++;
				pen[cont] += t + 20 * c[cont][p];
				c[cont][p]=-1;
			}
		}
		
		for(int i=0; i< MAXN; i++){
			if(part[i])
				res.push_back(i);
		}
		
		sort(res.begin(),res.end(),compare);
		
		for(size_t i=0; i<res.size(); i++)
			printf("%d %d %d\n", res[i], qtd[res[i]], pen[res[i]]);
		
		if(l == 'I')
			c[cont][p]++;
	}
    
    
    return 0;
}

