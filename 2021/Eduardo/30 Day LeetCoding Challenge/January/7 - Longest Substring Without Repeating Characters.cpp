class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> idx;
        
        int res = 0, left=-1;
        
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            if(idx.count(c)){
                left = max(left,idx[c]);   
            }
            
            idx[c]=i;
            
            res = max(res, i-left);
        }
        
        return res;
    }
};