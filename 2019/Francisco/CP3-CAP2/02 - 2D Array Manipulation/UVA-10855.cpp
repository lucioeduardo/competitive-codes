#include <bits/stdc++.h>
#define MAXN 1005

using namespace std;

int N, n, x, y, cont=0;
char big[MAXN][MAXN];
char small[MAXN][MAXN];
char temp[MAXN][MAXN];
int res[4];

int main(){ 

    while(true){

        scanf("%d %d", &N, &n);

        if(N == 0 && n == 0) break;


        for(int i=0; i<N; i++){
            scanf("%s", big[i]);
        }

        for(int i=0; i<n; i++){
            scanf("%s", small[i]);
        }

        for(int rot=0; rot < 4; rot++){
            x=0, y=0;
            
            for(int k = 1; k <= (N-n+1)*(N-n+1); k++){
                
                cont = 0;

                for(int i=0; i < n; i++){
                    for(int j=0; j < n; j++){
                        if(small[i][j] != big[i+x][j+y]){
                            break;                        
                        }
                        cont++;
                    }
                }

                y++;
                if(k%(N-n+1) == 0){
                    y=0;
                    x++;
                }

                if(cont==n*n) res[rot]++;

            }  

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    temp[i][j] = small[i][j];
                }
            }

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    small[i][j] = temp[n-1-j][i];
                }
            }

        }

        for(int i = 0; i < 4; i++){
            printf("%d", res[i]);
            if(i != 3) printf(" ");
        }
        printf("\n");

        memset(res,0,sizeof(res));
    }


    return 0;
}
