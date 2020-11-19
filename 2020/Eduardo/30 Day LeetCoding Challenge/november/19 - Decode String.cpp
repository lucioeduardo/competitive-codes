class Solution {
public:
    string decodeString(string s) {
        string res="";
        bool in=false;
        string act="", dig="";    
        int rep=0;
        int q=0;
        
        for(char c: s){
            
            if(in && q && !(q == 1 && c == ']')){
                act += c;
                
                if(c == '[') q++;
                if(c == ']') q--;
                
                continue;
            }
            
            if(c == '['){
                q++;
                rep = stoi(dig);
                in = true;
                continue;
            }
            
            if(c == ']'){
                q--;
                act=decodeString(act);
                while(rep--) res += act;
                act="";
                dig="";
                in=false;
                continue;
            }
            
            if(!in){
                if(isdigit(c)){
                    dig += c;
                }else res += c;
            }
                
        }
        
        return res;
    }
};