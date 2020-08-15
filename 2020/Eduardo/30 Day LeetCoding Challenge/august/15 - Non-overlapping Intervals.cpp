bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        
        if(intervals.size() == 0) return 0;
        
        vector<int> act = intervals[0];
        int res=0;
        
        for(int i=1; i<intervals.size(); i++){
            vector<int> v = intervals[i];
                        
            if(v[0] >= act[1]){
                act = v;
                continue;  
            } 
            
            res++;
            if(v[1] < act[1])
                act = v;
        }
        
        return res;
    }
};