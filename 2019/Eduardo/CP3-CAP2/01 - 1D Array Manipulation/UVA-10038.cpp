#include <bits/stdc++.h>
#define MAXN 3030
using namespace std;

bool value[MAXN];

int main(){
    int n;

    while(scanf("%d",&n) != EOF){
		
		memset(value, false, sizeof(value));
		
        int ant=0;
        for(int i=0; i<n; i++){
            int v;
            scanf("%d",&v);
            if(i > 0 && abs(ant-v) <= n)
                value[abs(ant-v)] = true;
            ant=v;
        }

        bool flag=true;

        for(int i=1; i<n; i++){
            if(!value[i])
                flag = false;
        }

        if(flag)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return 0;
}
