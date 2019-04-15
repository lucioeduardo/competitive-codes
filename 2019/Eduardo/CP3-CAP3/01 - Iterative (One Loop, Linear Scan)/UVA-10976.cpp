#include <bits/stdc++.h>
using namespace std;

vector<int> res;

int main(){
    int k;

    while(scanf("%d",&k) != EOF){
        res.clear();
        for(int i=k+1; i <= 2*k; i++){
            int n = i*k;
            int d = (i-k);

            if(n % d == 0){
                res.push_back(i);
            } 
        }

        printf("%d\n",res.size());

        
        for(size_t i = 0; i < res.size(); i++){
            int v = res[i];
            int n = v*k;
            int d = (v-k);

            printf("1/%d = 1/%d + 1/%d\n",k,n/d,v);
        }
        
    }
    return 0;
}