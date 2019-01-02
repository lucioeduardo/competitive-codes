#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

vector<char> pilhas;

int main(){
	int c=0;
	string s;
	
	while(cin>>s and s != "end"){
		pilhas.clear();
		for(size_t i=0; i<s.length(); i++){
			char c = s[i];
			vector<char>::iterator it = lower_bound(pilhas.begin(), pilhas.end(), c);
			
			if(it == pilhas.end()) pilhas.push_back(c);
			else *it = c;
		}
		
		printf("Case %d: %d\n",++c, (int)pilhas.size());
	}
	
    
    
    return 0;
}



