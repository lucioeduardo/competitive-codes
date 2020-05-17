class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        
        int nP[26], at[26];
        
        for(int i=0;i<26;i++) nP[i]=at[i]=0;
        
        for(char c: p){
            nP[c-'a']++;
        }
                
        int left=0;
        
        for(int i=0; i<s.length(); i++){
            int v = s[i]-'a';
            
            at[v]++;
            
            while(at[v] > nP[v] || i-left+1 > p.length()){
                at[s[left++] - 'a']--;
            }
            
            if(i-left+1 == p.length()) res.push_back(left);
        }
        
        return res;
    }
    

};