#include <bits/stdc++.h>
using namespace std;

bool score[61];

int main() {
    int N;
    string corner(70, '*');

    for(int i=0; i<=20; ++i)
        for(int j=1; j<=3; ++j)
            score[i * j] = 1;

    score[50] = 1;

    while(cin >> N && N > 0) {
        int combinations = 0;
        int permutations = 0;

        for(int i=0; i<61; ++i) {
            if(score[i])
            for(int j=i; j<61; ++j) {
                if(score[j])
                for(int k=j; k<61; ++k) {
                    if(score[k] && (i+j+k) == N){
                        ++combinations;

                        if(i != j && j != k && i != k)
                            permutations += 5;
                        else if(i != j || j != k || i != k)
                            permutations += 2;
                    }
                }
            }
        }
        if(combinations){
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << N << " IS " << combinations << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << N << " IS " << permutations + combinations << "." << endl;
        } else {
            cout << "THE SCORE OF " << N << " CANNOT BE MADE WITH THREE DARTS." << endl;
        }
        
        cout << corner << endl;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}