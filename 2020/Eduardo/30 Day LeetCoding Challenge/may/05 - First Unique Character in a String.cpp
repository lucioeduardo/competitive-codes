class Solution {
public:
    int firstUniqChar(string s) {
        int first[260];
        for(int i=0; i<260; i++) first[i]=-1;
        
        int idx=0;
        for(char c: s){
            if(first[c] == -1)
                first[c] = idx;
            else first[c] = 9999999;
            
            idx++;
        }
        
        int res = 9999999;
        for(int i=0; i<260; i++){
            if(first[i] != -1) res = min(res,first[i]);
        }
        
        return res == 9999999 ? -1 : res;
    }
};