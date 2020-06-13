#define MAXN 10010

class Solution {
public:
    vector<int> graph[MAXN];
    int depth[MAXN], p[MAXN];
    bool vis[MAXN];
    
    void solve(int x){
        vis[x]=true;
        
        for(int i=0; i<graph[x].size(); i++){
            int u = graph[x][i];
            if(!vis[u] || depth[x]+1 > depth[u]){
                depth[u]=depth[x]+1;
                p[u]=x;
                solve(u);
            }
        }
    }
    
    void generateList(int x, vector<int>& resList, vector<int>& nums){
        if(p[x] == x)
            resList.push_back(nums[x]);
        else{
            generateList(p[x], resList, nums);
            resList.push_back(nums[x]);
        }
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return vector<int>();
        
        sort(nums.begin(),nums.end());
        
        memset(vis,false,sizeof(vis));            
            
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[j] % nums[i] == 0)
                    graph[i].push_back(j);
            }
        }
        
        int res=0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                p[i]=i;
                depth[i]=0;
                solve(i);
            }
            
            if(depth[i] > depth[res]) res=i;
        }
        
        vector<int> resList;
        generateList(res, resList, nums);
        
        return resList;
    }
};