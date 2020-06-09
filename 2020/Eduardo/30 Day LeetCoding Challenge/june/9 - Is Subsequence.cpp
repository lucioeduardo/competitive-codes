class Solution {
public:
    bool isSubsequence(string s, string t) {
        int it=0;
        
        for(char c: t){            
            if(c == s[it])
                it++;
            
            if(it == s.length()) return true;
        }
        
        return it == s.length();
    }
};