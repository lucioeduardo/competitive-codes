class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        
        for(int i=0; i<=num; i++){
            int q=0, v=i; 
            
            while(v > 0){
                q++;
                v -= (v&-v);
            }
            
            res[i]=q;
        }
        
        return res;
    }
};