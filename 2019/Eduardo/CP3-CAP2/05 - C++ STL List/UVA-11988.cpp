#include <bits/stdc++.h>
using namespace std;

list<string> lista;

int main(){
	string s;
	
	while(getline(cin,s)){
		lista.clear();
		bool open=false;
		string aux = "";
		
		for(size_t i=0; i<s.length(); i++){
			if(s[i] == '['){
				if(open) lista.push_front(aux);
				else lista.push_back(aux);
				open = true;
				aux = "";
			}else if(s[i] == ']'){
				if(open) lista.push_front(aux);
				else lista.push_back(aux);
				open = false;
				aux = "";
			}else{
				aux += s[i];
			}
		}
		
		if(open) lista.push_front(aux);
		else lista.push_back(aux);
		
		for(list<string>::iterator it = lista.begin(); it != lista.end(); it++){
			cout << *it;
		}
		cout << endl;
	}
    return 0;
}


