class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> seen;
    
        int res=0;
        
        for(int num: nums){
            seen[num]++;
        }
        
        for(int num: nums){
            if(seen[num] == 1) return num;
        }
        
        return -1;
    }
};