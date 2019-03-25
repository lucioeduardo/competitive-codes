#include <bits/stdc++.h>
using namespace std;

double F[15], R[15];
double calc[105];

int main() {
    int f, r;
    
    while(cin >> f >> r) {

        for(int i=0; i<f; ++i)
            cin >> F[i];

        for(int i=0; i<r; ++i)
            cin >> R[i];

        for(int i=0; i<f; ++i)
            for(int j=0; j<r; ++j)
                calc[i * r + j] = R[j]/F[i];

        sort(calc, calc+r*f);
        double answer = 0;

        for(int i=1; i < r*f; ++i)
            answer = max(answer, calc[i]/calc[i-1]);

        cout << fixed << setprecision(2) << answer << endl;
    }
    return 0;
}