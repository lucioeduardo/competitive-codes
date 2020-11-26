class Solution {
public:
    
    int solve(string &s, int k, int l, int r){
        int prev=l;
        map<char,int> freq;
        int res=0;
        
        for(int i=l; i<r; i++){
            char c = s[i];
            freq[c]++;
        }
        
        for(int i=l; i<r; i++){
            if(freq[s[i]] < k){
                res = max(res, solve(s,k,prev,i));
                prev=i+1;
            }
        }
                
        if(prev == l)
            res = max(res, r-prev);
        else
            res = max(res, solve(s,k,prev,r));
        
        return res;
    }
    
    
    int longestSubstring(string s, int k) {
        return solve(s,k,0,s.length());
    }
};