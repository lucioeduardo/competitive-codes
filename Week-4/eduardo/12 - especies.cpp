// URI 1260 - Espécies de Madeira
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> qtd;

int main(){
	int n;
	
	scanf("%d ",&n);
	
	string str;
	//if(str == "") printf("opa\n");
	//cout<<"a"<<str<<"b"<<endl;


	for(int i=0; i<n; i++){
		qtd.clear();
		int total=0;
		while(getline(cin, str) && str != ""){
			if(qtd.find(str) == qtd.end())
				qtd[str]=1;
			else
				qtd[str]++;
			total++;
		}
		
		for(map<string,int>::iterator it = qtd.begin(); it!=qtd.end(); it++){
			cout << it->first;
			printf(" %.4lf\n",(100.0*(double)it->second)/total);
		}
		
		if(i<n-1)printf("\n");
	}
	
	
	return 0;
}
