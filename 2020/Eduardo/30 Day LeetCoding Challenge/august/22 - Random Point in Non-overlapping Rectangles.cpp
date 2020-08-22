class Solution {
public:
    vector<vector<int>> rects;
    vector<int> x, y;
    int sum=0;
    map<int,int> area;
    
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        
        int it=0;
        for(vector<int> p : rects){
            sum += (p[2]-p[0]+1)*(p[3]-p[1]+1);
            
            area[sum]= it;
            
            it++;
        }
    }
    
    vector<int> pick() {
        int rng = rand()%sum;
        
        int v = area.upper_bound(rng)->second;
        vector<int> rec = rects[v];
        
        int x = rec[2]-rec[0]+1;
        int y = rec[3]-rec[1]+1;
        
        return {rand()%x + rec[0], rand()%y + rec[1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */