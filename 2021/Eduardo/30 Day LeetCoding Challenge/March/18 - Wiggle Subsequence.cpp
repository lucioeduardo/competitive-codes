
class Solution {
public:
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        
        int last=nums[0];
        int x=-1;
        int res=1;
        
        // 1 - buscando um maior
        // 2 - buscando um menor
        
        for(int i=0; i<n; i++){
            if(nums[i] == last) continue;
            
            if(nums[i] > last){
                last = nums[i];
                if(x != 2){
                    x=2;
                    res++;   
                }
            }else{
                last = nums[i];
                if(x!=1){
                    x=1;
                    res++;
                }
            }
        }
        
        return res;
    }
};