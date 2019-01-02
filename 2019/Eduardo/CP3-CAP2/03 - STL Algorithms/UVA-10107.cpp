#include <bits/stdc++.h>
using namespace std;

vector<int> lista;

int main() {
	int n;
	
	while(scanf("%d",&n) != EOF){
		vector<int>::iterator it = lower_bound(lista.begin(),lista.end(),n);
		
		lista.insert(it, n);
		int tam = lista.size();
		
		if(tam % 2){
			printf("%d\n",lista[tam/2]);
		}else{
			printf("%d\n",(lista[tam/2] + lista[tam/2 - 1])/2);
		}
	}
	
	
	return 0;
}

