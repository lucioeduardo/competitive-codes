#include <cstdio>

int g[5][5];

int sX[4] = {1,0,-1,0};
int sY[4] = {0,1,0,-1};

void func(){
	int aux[5][5];
	
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			int s = 0;
			for(int k=0; k<4;k++)
				s += g[i+sX[k]][j+sY[k]];
			aux[i][j] = s % 2;
		}
	}
	
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			g[i][j] = aux[i][j];
	
}

bool zero(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(g[i][j] == 1) return false;
	return true;
}

int main(){
	int n;
	
	scanf("%d",&n);
	
	for(int k=0;k<n;k++){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				scanf("%1d",&g[i][j]);
			}
		}
		
		int res=-1;
		
		while(!zero()){
			func();
			
			res++;
		}
		
		printf("%d\n",res);
		
		
	}
	return 0;
}
