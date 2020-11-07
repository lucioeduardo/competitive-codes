class Solution {
public:
    int div(int a, int b){
        int s = (a%b != 0);
        
        return a/b + s;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, r = 1000100;
        
        int res=-1;
        
        while(l <= r){
            int m = (l+r)/2;
            
            int sum=0;
            
            for(int num: nums){
                sum += div(num,m);
            }
                        
            if(sum <= threshold){
                res=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        
        return res;
    }
};