class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n+1,false);
        
        int a,b;
        
        for(int x: nums){
            if(seen[x])
                a=x;
            seen[x]=true;
        }
        
        for(int i=1; i<=n; i++){
            if(!seen[i])
                b=i;
        }
        
        return {a,b};
    }
};