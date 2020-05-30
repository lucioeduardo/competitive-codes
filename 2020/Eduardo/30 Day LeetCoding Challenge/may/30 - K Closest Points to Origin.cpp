bool compare(vector<int>& a, vector<int>& b){
    return(a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1]);
}

class Solution {
public:
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(), points.end(), compare);
        
        vector<vector<int>> res(points.begin(), points.begin()+K);
        return res;
    }
};