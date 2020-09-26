class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int last=0;
        int res=0;
        
        for(int num: timeSeries){
            res += (num+duration) - max(last,num);
            last = num+duration;
        }
        
        return res;
    }
};