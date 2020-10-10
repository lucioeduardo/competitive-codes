bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(!points.size()) return 0;
        
        sort(points.begin(),points.end(),compare);
        
        int l=points[0][0], r = points[0][1];
        int res=1;
        
        for(vector<int> &v: points){
            if(v[0] <= r){
                l = max(l,v[0]);
                r = min(r, v[1]);
            }else{
                res++;
                l = v[0];
                r = v[1];
            }
        }
        
        return res;
    }
};