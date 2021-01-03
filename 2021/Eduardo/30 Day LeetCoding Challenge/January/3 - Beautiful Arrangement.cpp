class Solution {
public:
    
    int used[20];
    
    int solve(int idx, int n){
        if(idx == n+1) return 1;
        
        int res = 0;
        
        for(int i=1; i<=n; i++){
            if(!used[i] && ((i % idx == 0) || (idx % i == 0))){
                used[i]=true;
                res += solve(idx+1,n);
                used[i]=false;
            }
        }
        
        return res;
    }
    
    int countArrangement(int n) {
        for(int i=1; i<=n; i++) used[i]=false;
        
        return solve(1,n);
    }
};