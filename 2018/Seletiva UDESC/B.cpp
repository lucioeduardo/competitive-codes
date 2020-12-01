#include <bits/stdc++.h>
#define MAXN 70
#define INF 1000000000
using namespace std;

typedef struct {
	double x,y,z;
} POINT;

map<string, int> id;
double dist[MAXN][MAXN];

double distance(POINT v1, POINT v2) {
	return sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2));
}

int main()
{
	int t, p, w, q;
	string planet1, planet2;
	POINT v[MAXN];

	scanf("%d", &t);

	for(int k=1; k<=t; ++k) {
		scanf("%d", &p);

		for(int i=0; i<p; ++i) {
			cin >> planet1;
			scanf("%lf %lf %lf", &v[i].x, &v[i].y, &v[i].z);
			id[planet1] = i;
		}

		for(int i=0; i<p; ++i) {
			for(int j=0; j<p; ++j) {
				dist[i][j] = dist[j][i] = i^j ? INF : 0;
			}
		}

		for(int i=0; i<p; ++i) {
			for(int j=i+1; j<p; ++j) {
				dist[i][j] = dist[j][i] = distance(v[i], v[j]);
			}
		}

		scanf("%d", &w);

		while(w--) {
			cin >> planet1 >> planet2;
			dist[id[planet1]][id[planet2]] = 0.0;
		}

		for(int l=0; l<p; ++l) {
			for(int i=0; i<p; ++i) {
				for(int j=0; j<p; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
				}
			}
		}

		scanf("%d", &q);
		printf("Caso %d:\n", k);
		while(q--) {
			cin >> planet1 >> planet2;
			printf("A distancia de %s para %s eh %.0lf parsecs.\n", planet1.c_str(), planet2.c_str(), dist[id[planet1]][id[planet2]]);
		}

		id.clear();
	}
	return 0;
}