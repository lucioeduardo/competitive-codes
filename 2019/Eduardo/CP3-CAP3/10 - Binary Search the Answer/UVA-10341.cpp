#include <bits/stdc++.h>
#define e 2.718281828459045
#define EPS 0.0000001
using namespace std;

int p,q,r,s,t,u;


long double calculate(long double x){
	return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*pow(x,2) + u);
}

long double solve(){
	long double esq = 0, dir = 1;

	for(int i=0; i<1000; i++){
		long double meio = (esq+dir)/2;

		long double val = calculate(meio);

		if(val < 0)
			dir=meio;
		else
			esq=meio;
		
		if(abs(val) < EPS){
			//printf("ENTROU %Lf %Lf\n", meio, val);
			return meio;
			break;
		}
	}

	return esq;
}



int main(){
	
	while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u) != EOF){
		long double res = solve();

		//printf("%lf %lf\n", res, calculate(res));

		if(abs(calculate(res)) < EPS)
			printf("%.4Lf\n",res);
		else
			printf("No solution\n");
	}

	return 0;
}
