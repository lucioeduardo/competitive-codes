class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> pos;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == c)
                pos.push_back(i);
        }
        
        int it=0;
        
        vector<int> res;
        
        for(int i=0; i<s.length(); i++){
            int v = abs(i-pos[it]);
            if(it < pos.size()-1 && abs(pos[it+1]-i) < v){
                it++;
                v = abs(i-pos[it]);
            }
            
            res.push_back(v);
        }
        
        return res;
    }
};