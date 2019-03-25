#include <bits/stdc++.h>
#define MAXN 10
using namespace std;

char pass[MAXN][MAXN], grid[MAXN][MAXN];
int counter=0, k;
string res;


void solve(int idx, string password){
	if(counter == k)
		return;
	
	if(idx == 5){
		counter++;
		if(counter == k)
			res=password;
		return;
	}

	for(int j=0; j<6; j++){

		char c = pass[idx][j];
		bool can = false;

		if(pass[idx][j] == pass[idx][j+1])
			continue;

		for(int k=0; k<6; k++){
			if(grid[k][idx] == c)
				can=true;
		}

		if(can) solve(idx+1, password+c);
	}
	
	
}

int main(){
	int t;

	scanf("%d ",&t);

	while(t--){
		scanf("%d ",&k);

		for(int i=0;i<6;i++){
			for(int j=0;j<5;j++){
				scanf("%c", &pass[j][i]);
			}
			getchar();
		}

		for(int i=0;i<6;i++) sort(pass[i], pass[i]+6);

		for(int i=0;i<6;i++){
			for(int j=0;j<5;j++){
				scanf("%c", &grid[i][j]);
			}
			getchar();
		}

		counter=0;
		solve(0,"");

		if(counter < k) res = "NO";
		cout << res << endl;
	}


	return 0;
}
