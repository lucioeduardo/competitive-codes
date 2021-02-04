class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> count;
        
        for(int x: nums)
            count[x]++;
        
        int res = 0;
        
        for(int x: nums){
            int a = (count[x]+count[x-1])*(count[x-1]>0);
            int b = (count[x]+count[x+1])*(count[x+1]>0);
            
            res = max(res, max(a,b));
        }
            
        return res;
    }
};