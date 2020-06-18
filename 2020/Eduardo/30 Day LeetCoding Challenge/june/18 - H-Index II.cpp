class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        
        int res = 0;
        int l=1,r=n;
        
        while(l <= r){
            int m = (l+r)/2;
            
            if(citations[n-m] >= m){
                res=m;
                l = m+1;
            }
            else
                r = m-1;
        }
        
        
        return res;
    }
};