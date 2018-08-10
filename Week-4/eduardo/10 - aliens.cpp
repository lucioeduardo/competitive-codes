#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<string> values;

int main(){
	int n;
	
	while(scanf("%d",&n) && n!=0){
		values.clear();
		
		string str;
		for(int i=0;i<n;i++){
			cin>>str;
			sort(str.begin(),str.end());
			values.push_back(str);
		}
		
		sort(values.begin(), values.end());
		
		string ant= "0";
		int qtd=0;
		for(int i=0;i<n;i++){
			if(values[i] != ant){
				qtd++;
				ant=values[i];
			}
		}
		
		printf("%d\n",qtd);
	}
	
	return 0;
}
