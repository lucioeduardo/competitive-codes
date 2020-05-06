class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> m;
        
        int s = nums.size()/2;
        
        for(int num: nums){
            m[num]++;
            if(m[num] > s)
                res = num;
        }
        
        return res;
    }
};