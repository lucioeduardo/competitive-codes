class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count[60];
        
        for(int i=0; i<60; i++) count[i]=0;
        
        int res=0;
        
        for(int t: time){
            int r = t%60;
            
            res += count[(60-r)%60];
            
            count[r]++;
        }
        
        return res;
    }
};