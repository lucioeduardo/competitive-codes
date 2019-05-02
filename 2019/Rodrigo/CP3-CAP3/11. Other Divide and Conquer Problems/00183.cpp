#include <bits/stdc++.h>
using namespace std;

int n, m, ind, newLine;
char c, str[205][205];

char check(int a, int b, int x, int y) {
    bool zero = 0, one = 0;

    for(int i=a; i<=x; ++i) {
        for(int j=b; j<=y; ++j) {
            if(str[i][j] == '0') zero = 1;
            else one = 1;
        }
    }
    return zero && one ? 'D' : zero ? '0' : '1';
}

void solveB(int a, int b, int x, int y) {   
    if(a > x || b > y)
        return ;
    
    char curr = check(a, b, x, y);
    putchar_unlocked(curr);

    if(++newLine%50 == 0)
        putchar_unlocked('\n');

    if(a == x && b == y)
        return;
    if(curr == 'D') {
        int ha = (a+x)/2;
        int hb = (b+y)/2;

        solveB(a, b, ha, hb);
        solveB(a, hb+1, ha, y);
        solveB(ha+1, b, x, hb);
        solveB(ha+1, hb+1, x, y);
    }
}

void solveD(int a, int b, int x, int y) {
    if(a > x || b > y)
        return ;

    while(scanf("%c", &c) && c != '0' && c != '1' && c != 'D');
    
    if(c != 'D') {
        for(int i=a; i<=x; ++i)
            for(int j=b; j<=y; ++j)
                str[i][j] = c;
    } else {
        int ha = (a+x) / 2;
        int hb = (b+y) / 2;

        solveD(a, b, ha, hb);
        solveD(a, hb+1, ha, y);
        solveD(ha+1, b, x, hb);
        solveD(ha+1, hb+1, x, y);
    }
}

int main() {

    while(scanf("%c %d %d", &c, &n, &m) == 3)
    {
        newLine = 0;

        if(c == 'B') {
            for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                    scanf("%c", &str[i][j]);

                    char t = str[i][j];
                    if(t != '0' && t != '1' && t != 'D')
                        --j;
                }
            }            

            printf("D%4d%4d\n", n, m);
            solveB(0, 0, n-1, m-1);
            putchar_unlocked('\n');

        } else {
            printf("B%4d%4d\n", n, m);
            solveD(0, 0, n-1, m-1);

            for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j, ++newLine) {
                    printf("%c", str[i][j]);

                    if((newLine+1) % 50 == 0)
                        printf("\n");
                }
            }
            if(newLine % 50)
                printf("\n");
        }
        getchar();
    }
    return 0;
}