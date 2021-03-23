#define M 1000000007

class Solution {
public:
    
    int threeSumMulti(vector<int>& arr, int target) {
        int qtd[110];
        int n = arr.size();
        
        memset(qtd, 0, sizeof(qtd));
        
        for(int x: arr){
            qtd[x]++;
        }
        
        int res=0;
        
        for(int i=0; i<= 100; i++){
            if(qtd[i] < 1) continue;
            for(int j=i; j <= 100; j++){
                if(qtd[j] < 1) continue;
                for(int k=j; k<=100; k++){
                    if(qtd[k] < 1) continue;
                    int s = i+j+k;
                    
                    if(s == target){
                        int b = i == j ? qtd[i]-1 : qtd[j];
                        int c = j == k ? b-1 : qtd[k];
                        
                        long long sum = 1LL*qtd[i]*b*c;
                        
                        if(i == j && j == k) sum/=6;
                        else if(i == j || j == k) sum/=2;
                        
                        res += (sum%M);
                        
                        res %= M;
                    }
                    if(s > target) break;
                }
            }
        }
        
        return res;
    }
};