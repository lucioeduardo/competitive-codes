class Solution {
public:
    int n;
    
    bool test(string s, int i){
        if(i == n) return false;
        
        string p = s.substr(0,i);

        for(int j=i; j<n; j+=i){
            if(s.substr(j,i) != p)
                return false;
        }

        return true;
    }
    
    
    bool repeatedSubstringPattern(string s) {
        n = s.size();
        
        for(int i=1; i*i <= n; i++){
            if(n % i == 0){
                if(test(s,i) || test(s,n/i)) return true;
            }
        }
        
        return false;
    }
};