class Solution {
public:
    int n;
    
    bool dfs(int idx, vector<int>& arr, vector<bool> seen){
        //cout << idx << endl;
        seen[idx] = true;
        
        int u = idx + arr[idx];
        int v = idx - arr[idx];
        
        bool res= (arr[idx] == 0);
        
        if(u < n && !seen[u])
            res = res || dfs(u,arr,seen);
        
        if(v >= 0 && !seen[v])
            res = res || dfs(v,arr,seen);
        
        return res;
    }
    
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool> seen(n, false);
        
        return dfs(start, arr, seen);
    }
};