class Solution {
public:
    map<string, vector<string> > edges;
    map<string, bool> vis;
    
    void dfs(string s, vector<string>& res){
        sort(edges[s].begin(), edges[s].end());
        while(edges[s].size()){
            string next = edges[s][0];
            edges[s].erase(edges[s].begin());
            dfs(next,res);
        }
        res.push_back(s);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        
        for(vector<string> e: tickets){
            string a = e[0], b = e[1];
            vis[a] = false;
            vis[b] = false;
            
            edges[a].push_back(b);
            
        }
        
        vector<string> res;
        dfs("JFK", res);
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};