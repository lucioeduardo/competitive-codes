#include <bits/stdc++.h>
using namespace std;

int main() {

    int N;
    bool blankLine = false;

    while(cin >> N && N) {
        
        if(blankLine)
            cout << endl;
        else 
            blankLine = true;

        int v[N];

        for(int i=0; i<N; ++i)
            cin >> v[i];

        for(int i=0; i<N; ++i)
            for(int j=i+1; j<N; ++j)
                for(int k=j+1; k<N; ++k)
                    for(int l=k+1; l<N; ++l)
                        for(int m=l+1; m<N; ++m)
                            for(int n=m+1; n<N; ++n)
                                cout << v[i] << " " << v[j] << " " << v[k] << " " << v[l] << " " << v[m] << " " << v[n] << endl;
        
    }

    return 0;
}