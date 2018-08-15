#include <stdio.h>
#define MAX 51
#define M 1000000007

int m;

void identity(long long a[MAX][MAX]){
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            a[i][j] = (i==j);
}

void mmult(long long a[MAX][MAX], long long b[MAX][MAX]){
    long long temp[MAX][MAX];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++){
            temp[i][j] = 0;
            for(int k = 0; k < m; k++)
                temp[i][j] = (temp[i][j] + ((a[i][k] * b[k][j])%M))%M;
        }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = temp[i][j];
}

void mexpo(long long res[MAX][MAX], long long a[MAX][MAX], int n){
    identity(res);

    while(n > 0){
        if(n%2)
            mmult(res, a);
        mmult(a,a);
        n/=2;
    }
}

int main(){

    int t, n, i, j;
    scanf("%d", &t);

    long long matrix[MAX][MAX];
    long long res[MAX][MAX];
    
    while(t--){
        scanf("%d%d", &m,&n);

        for(i = 0; i < m; i++)
            for(j = 0; j < m; j++)
                scanf("%lld", &matrix[i][j]);

        mexpo(res, matrix, n);

        for(i = 0; i < m; i++)
            for(j = 0; j < m; j++){
                if((j+1)%m)
                    printf("%lld ", res[i][j]);
                else
                    printf("%lld\n", res[i][j]);
            }
    }
    
    return 0;
}