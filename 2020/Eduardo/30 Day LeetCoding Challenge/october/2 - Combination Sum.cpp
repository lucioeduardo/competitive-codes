class Solution {
public:
    vector<vector<int>> res;
    
    void solve(vector<int>& candidates, vector<int> act, int target, int idx){
        if(target == 0) res.push_back(act);
        
        for(int i=idx; i<candidates.size(); i++){
            int num = candidates[i];
            if(num <= target){
                vector<int> v = act;
                v.push_back(num);
                solve(candidates, v, target-num,i);
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, vector<int>(), target,0);
        
        return res;
    }
};