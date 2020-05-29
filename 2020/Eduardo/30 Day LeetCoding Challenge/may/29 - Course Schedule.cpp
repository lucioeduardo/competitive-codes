class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
        vector<int> graph[numCourses];
        
        int grau[numCourses];
        
        memset(grau,0,sizeof(grau));
        
        int qt=0;
        
        for(auto& v: prerequisites){
            int a = v[0], b=v[1];
            
            graph[b].push_back(a);
            grau[a]++;
        }
            
        queue<int> q;
        
        for(int i=0; i<numCourses; i++){
            if(grau[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int v = q.front();
            cout << v << endl;
            q.pop();
            qt++;
            
            for(int i=0; i<graph[v].size(); i++){
                int u = graph[v][i];
                grau[u]--;
                if(grau[u] == 0)
                    q.push(u);
                    
            }
        }
       
        return qt == numCourses;
    }
};