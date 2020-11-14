class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int l=1, r=20;
        
        int t = minutesToTest/minutesToDie;
                
        int res=0;
        while(pow(t+1,res) < buckets)
            res++;
        
        return res;
    }
};