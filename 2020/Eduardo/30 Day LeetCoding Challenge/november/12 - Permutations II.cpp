class Solution {
public:
    
    vector<vector<int>> res;
    map<int, int> qtd;
    int n;
    
    void solve(vector<int>& act, int idx){
        if(idx == n){
            res.push_back(act);
            return;
        }
        
        for(auto& kv: qtd){
            if(kv.second >= 1){
                act[idx] = kv.first;
                kv.second--;
                solve(act, idx+1);
                kv.second++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums){
        n =  nums.size();
        
        for(int num: nums){
            qtd[num]++;
        }
        
        vector<int> v(n);
        
        solve(v,0);
        
        return res;
    }
};