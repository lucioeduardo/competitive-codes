#include <bits/stdc++.h>
using namespace std;

int distance(int u, int v, int w, int i) {
    return (fabs(u - i/5) + fabs(v - i%5)) * w;
}

int main() {
    int t; cin >> t;
    int u[25], v[25], w[25];

    while(t--) {
        int n; cin >> n;

        for(int i=0; i<n; ++i)
            cin >> u[i] >> v[i] >> w[i];

        int totalCoust = 1e9;
        int answer[5];

        for(int i=0; i<25; ++i) {
            for(int j=i+1; j<25; ++j) {
                for(int k=j+1; k<25; ++k) {
                    for(int l=k+1; l<25; ++l) {
                        for(int m=l+1; m<25; ++m) {

                            int currentCoust = 0;
                            int office[] = {i, j, k, l, m};

                            for(int a=0; a<n; ++a) {
                                int dis = 1e9;

                                for(int b=0; b<5; ++b)
                                    dis = min(dis, distance(u[a], v[a], w[a], office[b]));

                                currentCoust += dis;
                            }

                            if(totalCoust > currentCoust) {
                                totalCoust = currentCoust;

                                for(int b=0; b<5; ++b)
                                    answer[b] = office[b];
                            }
                        }
                    }
                }
            }
        }
        for(int i=0; i<5; ++i) {
            if(i == 4)
                cout << answer[i] << endl;
            else
                cout << answer[i] << " ";
        }
    }
    return 0;
}