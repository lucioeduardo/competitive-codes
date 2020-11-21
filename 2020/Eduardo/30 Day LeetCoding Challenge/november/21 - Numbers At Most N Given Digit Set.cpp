class Solution {
public:
    int n;
    
    int solve(vector<string>& digits, vector<int>& n_dig, int f, int idx){
        
        
        if(idx == n_dig.size()-1 && f == 2) return 1;
        if(idx == n_dig.size()) return 1;
        if(f != 0) return 1 + digits.size()*solve(digits,n_dig,f,idx+1);
        
        int res=0;
        for(string c: digits){
            int d = c[0]-'0';
            
            if(d < n_dig[idx])
                res += solve(digits, n_dig, 1, idx+1);
            else if(d == n_dig[idx])
                res += solve(digits, n_dig, 0, idx+1);
            else if(idx < n_dig.size()-1)
                res += solve(digits, n_dig, 2, idx+1);
        }
        
        return res+(idx!=0);
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        this->n=n;
        vector<int> n_dig;
        
        while(n > 0){
            n_dig.push_back(n%10);
            n/=10;
        }
        
        reverse(n_dig.begin(), n_dig.end());
        
        
        return solve(digits,n_dig,0, 0);
    }
};