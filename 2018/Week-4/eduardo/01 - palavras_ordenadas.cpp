// SPOJ - https://br.spoj.com/problems/PALAVRMG/
#include <iostream>
using namespace std;

int main(){
	int n;
	string s;
	
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>s;
		bool flag = true;
		
		for(size_t j=0; j<s.length()-1; j++){
			//printf("%d %d\n",tolower(s[j]), tolower(s[j]+1));
			if(tolower(s[j]) >= tolower(s[j+1]))
				flag = false;
		}
		cout<<s<<": ";
		if(flag)
			cout<<"O"<<endl;
		else
			cout<<"N"<<endl;
	}
	
	return 0;
}
