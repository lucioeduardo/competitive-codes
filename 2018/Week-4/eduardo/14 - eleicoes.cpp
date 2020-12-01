#include <cstdio>
#include <map>
using namespace std;

map<int,int> voto;

int main(){
	int n,v;
	
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%d",&v);
	
		if(voto.find(v) == voto.end())
			voto[v] = 1;
		else
			voto[v]++;
	}
	
	int res = -1;
	voto[-1]=0;
	for(map<int,int>::iterator it = voto.begin(); it != voto.end(); it++){
		if(it->second > voto[res])
			res = it->first;
	}
	
	printf("%d\n",res);
	
	
	return 0;
}
