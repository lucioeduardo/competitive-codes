class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0,b=0;
        int idxA=-1,idxB=-1;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(idxA != -1 && nums[i] == nums[idxA])
                a++;
            else if(idxB != -1 && nums[i] == nums[idxB])
                b++;
            else if(a == 0){
                a++;
                idxA=i;
            }else if(b == 0){
                b++;
                idxB=i;
            }else{
                b--;
                a--;
            }
        }
        
        a=0;
        b=0;
        
        for(int i=0; i<n; i++){
            if(idxA != -1 && nums[i] == nums[idxA]) a++;
            if(idxB != -1 && nums[i] == nums[idxB]) b++;
        }
        
        vector<int> res;
        
        if(a > n/3) res.push_back(nums[idxA]);
        if(b > n/3) res.push_back(nums[idxB]);
        
        return res;
    }
};