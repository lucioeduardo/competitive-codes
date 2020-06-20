class Solution {
public:
    string getPermutation(int n, int k) {
        string v;
        
        for(int i=1;i<=n;i++){
            v += ('0'+i);
        }
        
        k--;
        
        while(k--){
            next_permutation(v.begin(),v.end());
        }
        
        return v;
    }
};