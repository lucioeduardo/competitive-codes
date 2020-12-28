class Solution {
public:
    int reachNumber(int target) {
        if(target < 0) target = -target;
        
        int n=-1;
        int l=1, r=49050;
        
        while(l <= r){
            long long m = (l+r)/2;
            
            long long v = (m*m+m)/2;
            
            //cout << m << " " << v << endl;
            
            if(v == target)
                return m;
            else if(v >= target){
                r=m-1;
                n=m;
            }else{
                l=m+1;
            }
        }
        
        
        int v = (n*n+n)/2;
        
        if((v-target) % 2 == 0)
            return n;
        else if((v+n+1-target) % 2 == 0)
            return n+1;
        
        return n+2;
    }
};