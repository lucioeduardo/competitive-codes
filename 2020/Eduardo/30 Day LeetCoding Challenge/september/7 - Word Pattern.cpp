class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n = pattern.length();
        
        vector<string> pat;
        int it=0;
        pat.push_back("");
        
        for(char c: str){
            if(c == ' '){
                pat.push_back("");
                it++;
            }else{
                pat[it] += c;
            }
        }
        
        map<char, string> m;
        set<string> vals;
        
        if(n != pat.size()) return false;
         
        for(int i=0; i<n; i++){
            char c = pattern[i];
        
            if(m.find(c) != m.end()){
                if(m[c] !=  pat[i])
                    return false;
            }else{
                if(vals.find(pat[i]) != vals.end())
                    return false;
                vals.insert(pat[i]);
                m[c] = pat[i];
            }
        }
        
        return true;
    }
};