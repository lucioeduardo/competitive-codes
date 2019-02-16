#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

struct area{
	int x, y, pop;
};

struct result{
	int a,b,c,d,e,val;
};

int distance(area a, area p){
	return (abs(a.x - p.x) + abs(a.y - p.y)) * p.pop;
}

vector<area> populated_areas;

int main(){
	int t;

	area areas[MAXN];
	int it=1;

	for(int i=0; i<5; i++)
		for(int j=0; j<5; j++)
			areas[it++] = {i,j,0};

	scanf("%d",&t);

	while(t--){
		populated_areas.clear();
		int n;
		scanf("%d",&n);

		result res = {1,2,3,4,5,99999999};

		for(int i=0; i<n; i++){
			int x,y,p;
			scanf("%d %d %d", &x,&y,&p);
			populated_areas.push_back({x,y,p});
		}

		for(int a=1; a<=21; a++){
		for(int b=a+1; b<=22; b++){
		for(int c=b+1; c<=23; c++){
		for(int d=c+1; d<=24; d++){
		for(int e=d+1; e<=25; e++){
			int points[5] = {a,b,c,d,e}; 
			int cost=0;
			for(int k=0; k<n; k++){
				int min_distance = 99999999;
				for(int j=0;j<5;j++){
					min_distance = min(min_distance, distance(areas[points[j]], populated_areas[k]));
				}
				cost += min_distance;
			}
			//printf("%d %d %d %d %d %d\n",a,b,c,d,e,cost);
			if(cost < res.val){
				res = {a,b,c,d,e,cost};
			}
		}}}}}

		printf("%d %d %d %d %d\n", res.a-1, res.b-1, res.c-1, res.d-1, res.e-1);
	}


	return 0;
}
