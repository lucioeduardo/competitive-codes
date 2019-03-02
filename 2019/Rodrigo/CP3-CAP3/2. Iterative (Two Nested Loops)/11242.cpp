#include <bits/stdc++.h>
using namespace std;

double F[15], R[15];
double ratio[105];

int main() {
    int f, r;
    
    while(cin >> f >> r) {

        for(int i=0; i<f; ++i)
            cin >> F[i];

        for(int i=0; i<r; ++i)
            cin >> R[i];

        for(int i=0; i<f; ++i)
            for(int j=0; j<r; ++j)
                ratio[i * r + j] = R[j]/F[i];

        sort(ratio, ratio+r*f);
        double answer = 0;

        for(int i=1; i < r*f; ++i)
            answer = max(answer, ratio[i]/ratio[i-1]);

        cout << fixed << setprecision(2) << answer << endl;
    }
    return 0;
}