class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string s){
        int l=0, r=s.length()-1;
        
        while(l <= r){
            if(s[l++] != s[r--]) return false;
        }
        
        return true;
    }
    
    void solve(string s, int idx, vector<string> act){
        if(idx == s.length()){
            res.push_back(act);
            return;
        }
        
        string str="";
        int n = act.size();
        act.push_back("x");
        
        for(int i=idx; i<s.length(); i++){
            str += s[i];
            if(isPalindrome(str)){
                act[n] = str;
                solve(s, i+1, act);
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        
        solve(s, 0, v);
        
        return res;
    }
};