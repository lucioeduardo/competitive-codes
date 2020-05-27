#define MAXN 2020

class Solution {
public:
    vector<int> graph[MAXN];
    int color[MAXN];
    
    
    bool dfs(int x){
        bool res = true;
        
        for(int i=0; i<graph[x].size(); i++){
            int b = graph[x][i];
            
            if(color[b] == -1){
                color[b]=!color[x];
                res &= dfs(b);
            }
                        
            if(color[b] == color[x]) {
                cout << b << " " << x << endl;
                return false;
            }
            
        }
        
        return res;
    }
    
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {         
        if(dislikes.empty()) return true;
                
        for(int i=1; i<=N; i++) color[i]=-1;
        
        for(auto& v : dislikes){
            int a=v[0], b=v[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        bool res = true;
        
        for(int i=1; i<=N; i++){
            if(color[i] == -1){
                color[i]=0;
                res &= dfs(i);
            }
        }
        
        return res;
    }
};