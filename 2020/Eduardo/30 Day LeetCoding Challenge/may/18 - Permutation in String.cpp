class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int qtd[26], at[26];
        
        for(int i=0; i<26; i++) qtd[i]=at[i]=0;
        
        for(char c: s1){
            qtd[c-'a']++;
        }
        
        int left=0;
        
        for(int i=0; i<s2.length(); i++){
            int v = s2[i]-'a';
            
            at[v]++;
            
            while(at[v] > qtd[v]){
                at[s2[left++]-'a']--;
            }
            
            if(i-left+1 == s1.length())
                return true;
        }
        
        return false;
    }
};