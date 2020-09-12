class Solution {
public:
    vector<vector<int>> res;
    
    void solve(int v, int k, int n, vector<int> act){
        if(n == 0 && k == 0) res.push_back(act);
        if(n <= 0 || k == 0) return;
        
        act.push_back(0);
        
        for(int i=v+1; i<=9; i++){
            act[act.size()-1]=i;
            solve(i,k-1,n-i,act);
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(0,k,n,vector<int>());
        
        return res;
    }
};