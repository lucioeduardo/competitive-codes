class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int q[n+1];
        memset(q,0,sizeof(q));
        
        for(int num: nums){
            q[num]++;
            if(q[num] == 2)
                res.push_back(num);
        }
        
        return res;
    }
};