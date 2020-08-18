class Solution {
public:
    vector<int> res;
    
    void solve(int num, int n, int k){
        if(n == 0){
            res.push_back(num);
            return;
        }
        if(num == 0){
            for(int i=1; i<=9; i++){
                solve(i, n-1, k);
            }
        }else{
            int v = num % 10;
            
            if(v - k >= 0) solve(num*10 + (v-k), n-1, k);
            if(k && v + k <= 9) solve(num*10 + (v+k), n-1, k);
           
        }
    }
    
    
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) res.push_back(0);
        solve(0,N,K);
        
        
        
        return res;
    }
};