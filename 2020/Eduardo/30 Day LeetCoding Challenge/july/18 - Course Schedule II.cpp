class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int g[numCourses];
        
        memset(g,0,sizeof(g));
        
        vector<int> adj[numCourses];
        
        for(vector<int> v: prerequisites){
            g[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        
        queue<int> ex;
        
        for(int i=0; i<numCourses; i++){
            if(g[i] == 0)
                ex.push(i);
        }
        
        vector<int> res;
        
        while(!ex.empty()){
            int v = ex.front(); ex.pop();
            res.push_back(v);
            
            for(int u: adj[v]){
                g[u]--;
                if(!g[u])
                    ex.push(u);
            }
        }
        
        if(res.size() != numCourses)
            res.clear();
        
        return res;
    }
};