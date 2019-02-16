#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

int main(){

    int s, b, l, r;
    pair<int, int> arr[MAXN];

    while(true){

        scanf("%d %d", &s, &b);

        if(s == 0 && b == 0) break;

        for(int i = 1; i <= s; i++){
            arr[i].first = i-1;
            arr[i].second = i+1;
        }

        for(int i = 0; i<b; i++){
            scanf("%d %d", &l, &r);

            arr[arr[l].first].second = arr[r].second;
            arr[arr[r].second].first = arr[l].first;
            
            if(arr[arr[r].second].first == 0){
            	printf("* ");
            } else{
            	printf("%d ", arr[arr[r].second].first);
            }
            
            if(arr[arr[l].first].second == s+1){
            	printf("*\n");
            } else{
            	printf("%d\n", arr[arr[l].first].second);
            }
        }
        printf("-\n");

    }

    return 0;
}