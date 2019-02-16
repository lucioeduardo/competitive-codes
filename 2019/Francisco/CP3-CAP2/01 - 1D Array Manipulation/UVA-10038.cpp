#include <bits/stdc++.h>
#define MAXN 3005

using namespace std;

int n, curr;
int seq[MAXN];
bool jolly[MAXN];

int main(){

    while(scanf("%d", &n) != EOF){
        int res=1;
        memset(jolly, 0, sizeof(jolly));

        for(int i = 0; i < n; i++){
            scanf("%d", &seq[i]);
        }

        for(int i = 1; i < n; i++){
            curr = abs(seq[i]-seq[i-1]);
            if(!jolly[curr]){
                jolly[curr] = 1; 
            }
        }

        for(int i=1; i<n; i++){
            if(!jolly[i]){
                res=0;
                break;
            }
        }

        if(res){
            printf("Jolly\n");
        } else{
            printf("Not jolly\n");
        }

    }

    return 0;
}