#include <cstdio>


int main(){
	int a,d;
	
	while(scanf("%d %d",&a,&d) && !(a == 0 && d == 0)){
		int v,min_at = -1;
		
		for(int i=0; i<a; i++){
			scanf("%d",&v);
			if(v < min_at || min_at==-1)
				min_at=v;
		}
		
		int qtd=0;
		for(int i=0;i<d;i++){
			scanf("%d",&v);
			if(v <= min_at)
				qtd++;
		}
		
		if(qtd >= 2)
			printf("N\n");
		else
			printf("Y\n");
	}
	
	return 0;
}
