class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> idx;
        vector<int> begs;
        
        for(int i=0; i<intervals.size(); i++){
            vector<int> v = intervals[i];
            idx[v[0]] = i;
            begs.push_back(v[0]);
        }
        
        sort(begs.begin(),begs.end());
        
        vector<int> res;
        
        for(int i=0; i<intervals.size(); i++){
            vector<int> v = intervals[i];
            
            vector<int>::iterator it = lower_bound(begs.begin(), begs.end(), v[1]);
            
            if(it == begs.end())
                res.push_back(-1);
            else{
                res.push_back(idx[*it]);
            }
            
        }
        
        return res;
    }
};