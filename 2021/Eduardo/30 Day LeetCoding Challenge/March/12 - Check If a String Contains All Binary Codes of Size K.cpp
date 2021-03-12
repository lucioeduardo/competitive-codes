class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> subs;
        
        if(k > s.size()) return false;
        
        for(int i=0; i<s.size()-k+1; i++){
            subs.insert(s.substr(i,k));
        }
        
        return subs.size() == 1<<k;
    }
};