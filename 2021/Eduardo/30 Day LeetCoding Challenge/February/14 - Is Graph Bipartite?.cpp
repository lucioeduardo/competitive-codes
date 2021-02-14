#define MAXN 110

class Solution {
public:
    
    vector<vector<int>> graph;
    int n;
    int group[MAXN];
    
    bool dfs(int x){
        
        bool res=true;
        
        for(int i=0; i<this->graph[x].size(); i++){
            int u = this->graph[x][i];
                        
            if(group[u] == group[x]) return false;
            
                
            if(group[u] == 0){
                group[u] = group[x] == 1 ? 2 : 1;
                res = res && dfs(u);
            }    
        }
        
        return res;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        this->graph = graph;
        n = graph.size();
        
        memset(group,0,sizeof(group));
        bool res=true;
        
        for(int i=0; i<n; i++){
            if(!group[i]){
                group[i]=1;
                res = res && dfs(i);
            }
            
            
        }
        
        return res;
    }
};