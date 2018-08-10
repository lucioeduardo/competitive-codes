// SPOJ - https://www.spoj.com/problems/HAMSTER1/
#include <cstdio>
#include <cmath>

int v=10, k1=10, k2=0;
double res(double angle){
	double x = ((v*v)*sin(2*angle))/10;
	double y = ((v*v)*sin(angle)*sin(angle))/20;
	
	return k1*x + k2*y;
}

int main(){
	int t;
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		scanf("%d %d %d",&v, &k1, &k2);
		
		double l = 0;
		double r = (M_PI_2);
		
		for(int i=0; i<100; i++){
			double m = (l+r)/2;
		
			if(res(l) > res(r))
				r = m;
			else
				l = m;
		}
		
		printf("%.3lf %.3lf\n",l, res(l));
	}
	

	
	return 0;
}
