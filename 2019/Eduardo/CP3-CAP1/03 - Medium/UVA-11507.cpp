#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	
	while(scanf("%d ", &n) && n){
		string s;
		string dir = "+x";
		for(int i=0; i<n-1; i++){
			cin>>s;
			
			if(s == "+y"){
				if(dir == "+x") dir = "+y";
				else if(dir == "-x") dir = "-y";
				else if(dir == "+y") dir = "-x";
				else if(dir == "-y") dir = "+x";
			}else if(s == "-y"){
				if(dir == "+x") dir = "-y";
				else if(dir == "-x") dir = "+y";
				else if(dir == "+y") dir = "+x";
				else if(dir == "-y") dir = "-x";
			}else if(s == "+z"){
				if(dir == "+x") dir = "+z";
				else if(dir == "-x") dir = "-z";
				else if(dir == "+z") dir = "-x";
				else if(dir == "-z") dir = "+x";
			}else if(s == "-z"){
				if(dir == "+x") dir = "-z";
				else if(dir == "-x") dir = "+z";
				else if(dir == "+z") dir = "+x";
				else if(dir == "-z") dir = "-x";
			}
		}
		
		cout << dir << endl;
	}
	
    return 0;
}
