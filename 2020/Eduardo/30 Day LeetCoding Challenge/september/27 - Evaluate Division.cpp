#define psd pair<string,double>

class Solution {
public:
    map<string, vector<psd>> graph;
    map<string,bool> seen;
    
    double dfs(string a, string b){
        seen[a]=true;
        
        for(int i=0; i<graph[a].size(); i++){
            string u = graph[a][i].first;
            double v = graph[a][i].second;
            
            if(u == b) return v;
            
            if(!seen[u]){
                double r = dfs(u,b);
                if(r != -1)
                    return v*r;
            }
        }
        
        return -1;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i=0;i<equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double v = values[i];
            
            graph[a].push_back({a,1});
            graph[b].push_back({b,1});
            graph[a].push_back({b,v});
            graph[b].push_back({a,1/v});
        }
        
        
        vector<double> res;
        
        for(vector<string> q: queries){
            seen.clear();
            res.push_back(dfs(q[0],q[1]));
        }
        
        return res;   
    }
};