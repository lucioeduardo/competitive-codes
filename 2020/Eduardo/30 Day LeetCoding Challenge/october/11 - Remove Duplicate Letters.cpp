class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, vector<int>> pos;
        
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            pos[c].push_back(i);
        }
        
        string res = "";
        int idx=0;
        
        while(!pos.empty()){
            int r = s.length()-1;
            
            for(char i='a'; i<='z'; i++){
                if(pos.count(i)){
                    r = min(r, *(pos[i].rbegin()));
                }
            }
            
            for(char i='a'; i<='z'; i++){
                if(pos.count(i)){
                    vector<int> &v = pos[i];
                    
                    int k = *lower_bound(v.begin(), v.end(), idx);
                    if(k <= r){
                        res += i;
                        pos.erase(i);
                        idx=k+1;
                        break;
                    }
                }
            }
            
        }
        
        return res;
    }
};