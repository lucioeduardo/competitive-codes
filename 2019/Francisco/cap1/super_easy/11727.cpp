// UVA - 11727 - Cost Cutting
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, emp[3];

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        scanf("%d %d %d", &emp[0], &emp[1], &emp[2]);
        sort(emp, emp+3);
        printf("Case %d: %d\n", i+1, emp[1]);
    }   

    return 0;
}