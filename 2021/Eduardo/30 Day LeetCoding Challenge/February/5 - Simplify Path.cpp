class Solution {
public:
    string simplifyPath(string path) {
        stack<string> p;
        
        string at = "";
        
        for(char c: path){            
            if(c == '/'){
                if(at == ".."){
                    if(!p.empty()) p.pop();
                }
                else if(at != "." && !at.empty())
                    p.push(at);
                
                at = "";
            }else{
               at += c;
            }
        }
        
        if(at == ".."){
            if(!p.empty()) p.pop();
        }
        else if(at != "." && !at.empty())
            p.push(at);
        
        string res = "";
        
        while(!p.empty()){
            res = "/" + p.top()  + res;
            p.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};