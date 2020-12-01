// SPOJ - https://www.spoj.com/problems/SUMFOUR/
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 2550
using namespace std;

int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
vector<int> ab,cd;

int main(){
	int n;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ab.push_back(a[i]+b[j]);
			cd.push_back(-(c[i]+d[j]));
		}
	}
	
	sort(cd.begin(),cd.end());
	int qtd=0;
	
	for(size_t i=0;i<ab.size();i++){
		vector<int>::iterator low = lower_bound(cd.begin(),cd.end(),ab[i]);
		vector<int>::iterator upp = upper_bound(cd.begin(),cd.end(),ab[i]);
		
		qtd += (upp - low);
	}
	
	printf("%d\n",qtd);
	
	return 0;
}
