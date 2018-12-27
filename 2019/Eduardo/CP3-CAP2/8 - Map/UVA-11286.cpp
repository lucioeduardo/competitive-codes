#include<bits/stdc++.h>
using namespace std;

map<string, int> freq;
string aux[5];

int main(){
	int n;
	
	while(cin>>n && n!=0){
		freq.clear();
		int qtd_m=0, res=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<5; j++)
				cin >> aux[j];
			sort(aux, aux+5);
			string join = "";
			
			for(int j=0; j<5; j++)
				join += aux[j];
				
			//cout << join << endl;
			
			freq[join]++;
			qtd_m = max(qtd_m, freq[join]);
		}
		
		for(map<string,int>::iterator it = freq.begin(); it!=freq.end(); it++){
			if(it->second == qtd_m) res += qtd_m;
		}
		
		printf("%d\n",res);
	}
	
	
	return 0;
}
