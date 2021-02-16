class Solution {
public:
    
    vector<string> res;
    
    void solve(string s, int idx){
        if(idx == s.size()) res.push_back(s);
        else{
            if(isdigit(s[idx])){
                solve(s, idx+1);
                return;
            }
            
            s[idx] = tolower(s[idx]);
            solve(s, idx+1);
            s[idx] = toupper(s[idx]);
            solve(s, idx+1);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        solve(S,0);
        return res;
    }
};