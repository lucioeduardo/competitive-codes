class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26];
        for(int i=0; i<26; i++) count[i]=0;
        
        for(char c: s){
            count[c-'a']++;
        }
        
        for(char c: t){
            int v = c-'a';
            count[v]--;
            
            if(count[v] < 0)
                return false;
        }
        
        return s.length() == t.length();
    }
};