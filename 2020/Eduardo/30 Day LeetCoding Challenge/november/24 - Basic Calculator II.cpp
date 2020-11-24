class Solution {
public:
    
    map<string, int> prec = {{"+",1}, {"-",1}, {"*",2}, {"/",2}};
    
    bool isOp(char c){
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }
    
    int solve(vector<string>& v, int l, int r) {
        if(r - l == 1) return stoi(v[l]);
        
        int b=-1;
        
        for(int i=r-1; i>=l; i--){
            if(isOp(v[i][0])){
                if(b == -1 || prec[v[i]] < prec[v[b]])b = i;
                
                if(prec[v[b]] == 1) break;
            }
                
        }
        
        int x = solve(v, l, b), y = solve(v,b+1,r);
         
        if(v[b] == "+")
            return x+y;
        else if(v[b] == "-")
            return x-y;
        else if(v[b] == "*")
            return x*y;
       
        return x/y;
    }
    
    int calculate(string s) {
        vector<string> v;
        string act="";
        
        for(char c: s){
            if(isOp(c)){
                v.push_back(act);
                string op="";
                op=c;
                v.push_back(op);
                act="";
            }else if(c != ' ')
                act += c;
        }
        
        if(!act.empty()) v.push_back(act);
        
        return solve(v, 0, v.size());
    }
};