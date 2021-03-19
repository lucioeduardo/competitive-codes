#define MAXN 1010

class Solution {
public:
    
    vector<vector<int>> graph;
    bool seen[MAXN];
    int count;
    
    void dfs(int x){
        seen[x] = true;
        count++;
        
        for(int i=0; i<graph[x].size(); i++){
            int u = graph[x][i];
            
            if(!seen[u])
                dfs(u);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        memset(seen, false, sizeof(seen));
        this->graph = rooms;
        count = 0;
        
        dfs(0);
        
        return count == rooms.size();
    }
};