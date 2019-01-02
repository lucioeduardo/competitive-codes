#include <bits/stdc++.h>
using namespace std;

string a,b;

void solve(string pilha, int idx, string res, string pr){
	int tam = pilha.length();
	if(idx == (int)a.length()){
		if(res == b){
			cout << pr.substr(0,pr.length()-1) << endl;
			return;
		}
		else if(tam > 0){
			if(b[res.length()] != pilha[tam-1])
				return;
			solve(pilha.substr(0,tam-1), idx, res + pilha[tam-1], pr + "o ");
		}
	}else{
	
		solve(pilha + a[idx], idx+1, res, pr + "i ");
		
		if(tam > 0 and b[res.length()] == pilha[tam-1])
			solve(pilha.substr(0,tam-1), idx, res + pilha[tam-1], pr + "o ");
	}
} 


int main(){
	
	while(cin>>a>>b){
		cout << "[" << endl;
		solve("",0,"","");
		cout << "]" << endl;
	}
    
    
    return 0;
}


