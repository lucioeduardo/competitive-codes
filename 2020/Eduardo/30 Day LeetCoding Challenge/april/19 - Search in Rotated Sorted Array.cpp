class Solution {
public:
    
    int bb(vector<int>&nums, int esq, int dir, int target){
        while(esq <= dir){
            int meio=(esq+dir)/2;
            
            if(nums[meio] == target)
                return meio;
            else if(nums[meio] > target)
                dir=meio-1;
            else
                esq=meio+1;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int l = nums.size();
        int pivot=l-1;
        
        if(!l) return -1;
        if(l == 1) return nums[0] == target ? 0 : -1;
        
        int esq=0; int dir=l-2;
        
        while(esq <= dir){
            int meio = (esq+dir)/2;
            
            if(nums[meio] > nums[meio+1]){
                pivot = meio;
                break;
            }
            
            if(nums[meio] >= nums[0]){
                esq=meio+1;
            }else{
                dir=meio-1;
            }
        }
        
        cout << pivot;
        
        int res = bb(nums,0,pivot,target);
        if(pivot < l-1) res = max(res, bb(nums,pivot+1,l-1,target));
        
        return res;
    }
};