bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        int r=0, res=0;
        
        for(vector<int> v: intervals){
            if(r < v[1]) res++;
            r = max(r,v[1]);
        }
        
        return res;
    }
};