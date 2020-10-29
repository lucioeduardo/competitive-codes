class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l=-1;
        int res=0;
        int n = seats.size();
        
        for(int i=0; i<n; i++){
            if(seats[i]){
                if(l == -1) res=max(res,i);
                else{
                    res = max(res, (i-l)/2);
                }
                l=i;
            }
        }
        
        res = max(res,(n-l-1));
        
        return res;
    }
};