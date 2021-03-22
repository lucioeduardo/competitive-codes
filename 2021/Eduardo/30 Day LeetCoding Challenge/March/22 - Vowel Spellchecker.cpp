class Solution {
public:
    
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    string toLowerAll(string a){
        string res = "";
        
        for(char c: a){
            res += tolower(c);
        }
        
        return res;
    }
    
    string toVowel(string a){            
        string res = "";
        
        for(char c: a){
            if(isVowel(c)) res += 'a';
            else res += tolower(c);
        }
        
        return res;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> res;
        
        set<string> words(wordlist.begin(), wordlist.end());
        map<string, string> insensitive;
        map<string, string> noVowel;
        
        for(string s: wordlist){
            string l = toLowerAll(s);
            
            if(!insensitive.count(l))
                insensitive[l]=s;
            
            string v = toVowel(s);
            
            if(!noVowel.count(v))
                noVowel[v]=s;
        }
        
        for(string q: queries){
            string l = toLowerAll(q);
            string v = toVowel(q);
            
            if(words.count(q))
                res.push_back(q);
            else if(insensitive.count(l))
                res.push_back(insensitive[l]);
            else
                res.push_back(noVowel[v]);
        }
        
        return res;
    }
};