#include <bits/stdc++.h>
#define MAXN 
using namespace std;

vector<string> a, b;
int n,m;

bool verify(int x, int y, vector<string>& v){
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			if(a[x+i][y+j] != v[i][j])
				return false;
		}
	}
	return true;
}

int main(){
	
	while(scanf("%d %d ",&n,&m) && n){
		a.clear();
		b.clear();
		
		string s;
		for(int i=0; i<n; i++){
			cin>>s;
			a.push_back(s);
		}
	
		for(int i=0; i<m; i++){
			cin>>s;
			b.push_back(s);
		}	
		
		int x=0,y=0,z=0,w=0;
		
		for(int i=0; i<=n-m; i++){
			for(int j=0; j<=n-m; j++){
				if(verify(i,j,b)) x++;
			}
		}
		
		vector<string> c(b);
		
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
				c[i][j] = b[m-j-1][i];
				
		for(int i=0; i<=n-m; i++){
			for(int j=0; j<=n-m; j++){
				if(verify(i,j,c)) y++;
			}
		}

		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
				c[i][j] = b[m-i-1][m-j-1];
				
		for(int i=0; i<=n-m; i++){
			for(int j=0; j<=n-m; j++){
				if(verify(i,j,c)) z++;
			}
		}

		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
				c[i][j] = b[j][m-i-1];
				
		for(int i=0; i<=n-m; i++){
			for(int j=0; j<=n-m; j++){
				if(verify(i,j,c)) w++;
			}
		}
		
		printf("%d %d %d %d\n",x,y,z,w);
	}
	
	return 0;
}
