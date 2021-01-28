class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string res = "";
        
        for(int i=1; i<n; i++){
            int m = max(1, k - (n-i)*26);
            res += ('a'+m-1);
            k-=m;
        }
        
        res += ('a'+k-1);
        
        return res;
    }
};