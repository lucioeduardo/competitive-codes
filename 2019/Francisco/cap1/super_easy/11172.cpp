#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, a, b;
    char c;

    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &a, &b);

        if(a < b) c = '<';
        else if(a > b) c = '>';
        else c = '=';

        printf("%c\n", c);
    }

    return 0;
}