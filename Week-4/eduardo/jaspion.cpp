#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<string, string> dict;

int main(){
	int t;
	
	scanf("%d ",&t);
	
	for(int i=0; i<t; i++){
		dict.clear();
		int n,m;
		
		scanf("%d %d ",&m, &n);
		
		for(int j=0; j<m; j++){
			string a,b;
			getline(cin, a);
			getline(cin, b);
			
			dict[a]=b;
		}
		
		for(int j=0; j<n; j++){
			string frase,p="";
			getline(cin, frase);
			
			for(size_t k=0; k<frase.length(); k++){
				if(frase[k] == ' '){
					if(dict.find(p) == dict.end())
						cout << p << " ";
					else
						cout << dict[p] << " ";
					
					p = "";
				}else
					p += frase[k];
			}
			
			if(dict.find(p) == dict.end())
				cout << p << endl;
			else
				cout << dict[p] << endl;
			
		}
		
		cout << endl;
	}
	
	return 0;
}
