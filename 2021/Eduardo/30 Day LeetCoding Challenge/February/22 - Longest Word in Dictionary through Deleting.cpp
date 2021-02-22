class Solution {
public:
   
    
    string findLongestWord(string s, vector<string>& d) {
        string res="";
        
        for(string x: d){
            if(x.length() < res.length()) continue;
            if(x.length() == res.length() && res < x) continue;
            
            int i=0;
            
            for(char c: s){
                if(i == x.length()) break;
                if(c == x[i])
                    i++;
            }
            
            if(i == x.length()) res=x;
        }
        
        return res;
    }
};