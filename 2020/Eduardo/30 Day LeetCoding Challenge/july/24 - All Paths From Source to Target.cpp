class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(vector<vector<int>>& graph, int node, vector<int> path){
        path.push_back(node);
        
        if(node == graph.size()-1){
            res.push_back(path);
            return;
        }
        
        for(int i=0; i<graph[node].size(); i++){
            
            solve(graph,graph[node][i], path);
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        
        solve(graph,0,{});
        
        return res;
    }
};