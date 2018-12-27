#include <bits/stdc++.h>
using namespace std;

map<string, int> freq;

int main(){
	int t;
	
	scanf("%d ", &t);
	
	for(int i=0; i<t; i++){
		string s;
		
		freq.clear();
		int qtd=0;
		
		while(getline(cin, s) && !s.empty()){
			qtd++;
			freq[s]++;
		}
		
		for(map<string,int>::iterator it = freq.begin(); it != freq.end(); it++){
			cout << it->first;
			printf(" %.4lf\n", ((double)it->second*100)/qtd);
		}
		
		if(i < t-1) cout << endl;
	}
	
	return 0;
}



