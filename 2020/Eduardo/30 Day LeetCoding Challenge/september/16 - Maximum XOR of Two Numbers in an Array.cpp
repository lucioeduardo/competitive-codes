class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        int res=0, mask=0;
        set<int> s;
        
        for(int i=30; i>=0; i--){
            
            mask |= (1<<i);
            
            for(int j=0; j<n; j++){
                s.insert(nums[j] & mask);
            }
            
            int cand = res | (1<<i);
            
            for(int v: s){
                if(s.count(v ^ cand)){
                    res=cand;
                    break;
                }
            }
            
            s.clear();
        }
        
        
        return res;
    }
};