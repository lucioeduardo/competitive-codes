bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        
        int l=intervals[0][0], r=intervals[0][1];
        
        for(auto& v: intervals){
            if(v[0] <= r) r = max(v[1],r);
            else{
                res.push_back({l,r});
                l=v[0];
                r=v[1];
            }
        }
        
        res.push_back({l,r});
        
        return res;
    }
};