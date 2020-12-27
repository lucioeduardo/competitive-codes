class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int> > idx;
        map<int, bool> seen_v;
                
        bool seen[n+1];
        
        for(int i=0; i<n; i++){
            int v = arr[i];
            
            seen[i]=false;
            
            idx[v].push_back(i);
        }
        
        queue<pair<int,int>> q;
        
        
        q.push({0,0});
        
        while(!q.empty()){
            pair<int,int> top = q.front(); q.pop();
                        
            int u=top.first, d=top.second;
            seen[u]=true;
            
            if(u == n-1) return d; 
            
            if(u > 0 && !seen[u-1]){
                seen[u-1]=true;
                q.push({u-1,d+1});
            }
            
            if(!seen[u+1]){
                seen[u+1]=true;
                q.push({u+1,d+1});
            }
            
            int val = arr[u];
            
            if(seen_v[val]) continue;
            
            seen_v[val]=true;
            for(int v: idx[arr[u]]){
                if(!seen[v]){
                    seen[v]=true;
                    q.push({v,d+1});
                }
            }
        }
        
        return -1;
    }
};