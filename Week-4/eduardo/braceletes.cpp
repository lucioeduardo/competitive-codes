// SPOJ - https://br.spoj.com/problems/BRACELMG/
#include <iostream>
#include <algorithm>
using namespace std;

bool is_substr(string a, string b){	
	int len = a.length();
	
	int i=0, count=0, qtd=0;
	while(true){
		if(a[count] == b[i]){
			count++;
		}else{
			count=0;
		}
		
		if(count == len)
			return true;
		
		i++;
		qtd++;
		
		if(qtd > (int)(b.length() + a.length()))
			break;
		i %= (int)b.length();
	}
	
	return false;
}

int main(){
	int n;
	string a, b;
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a>>b;
	
		string c(b.rbegin(), b.rend());
				
		if(is_substr(a,b) || is_substr(a,c))
			cout << "S"<<endl;
		else
			cout << "N"<<endl;
	}
	

	
	return 0;
}
