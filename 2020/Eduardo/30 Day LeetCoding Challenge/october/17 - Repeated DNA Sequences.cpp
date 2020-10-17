class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> qtd;
        
        string str = s.substr(0,10);
        
        vector<string> res;
        
        for(int i=10; i<s.length(); i++){
            qtd[str]++;
            
            if(qtd[str] == 2) res.push_back(str);
            
            str.erase(str.begin());
            str += s[i];
        }
        
        qtd[str]++;
        if(qtd[str] == 2) res.push_back(str);

        
        return res;
    }
};