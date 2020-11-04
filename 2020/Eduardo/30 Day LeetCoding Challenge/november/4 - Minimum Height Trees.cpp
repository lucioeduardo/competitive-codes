class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        
        vector<int> graph[n+1];
        int degree[n+1];
        
        memset(degree,0,sizeof(degree));
        
        for(vector<int> e: edges){
            int a=e[0], b=e[1];
            
            graph[a].push_back(b);
            graph[b].push_back(a);
            
            degree[a]++;
            degree[b]++;
        }
        
        queue<int> q;
        
        int v = n;
        
        for(int i=0; i<n; i++)
            if(degree[i] == 1) q.push(i);
        
        while(v > 2){
            int s = q.size();
            v -= s;
            
            while(s--){
                int u = q.front();
                q.pop();
                
                //cout << u << endl;
                
                for(int i=0; i<graph[u].size(); i++){
                    int k = graph[u][i];
                    degree[k]--;
                    
                    if(degree[k] == 1)
                        q.push(k);
                }
            }
        }
        
        vector<int> res;
        res.push_back(q.front());q.pop();
        if(q.size()) res.push_back(q.front());q.pop();
        
        return res;
    }
};