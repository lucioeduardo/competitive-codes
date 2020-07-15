class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        string w = "";
        for(char c: s){
            cout << w << endl;
            if(c == ' '){
                if(!w.empty()){
                    words.push_back(w);
                }
                w = "";
            }else{
                w += c;
            }
        }
        if(!w.empty()){
            words.push_back(w);
        }
        
        string res = "";
        
        
        
        for(int i=words.size()-1; i>=0; i--){
            res += words[i];
            
            if(i > 0) res += ' ';
        }
        
        return res;
    }
};