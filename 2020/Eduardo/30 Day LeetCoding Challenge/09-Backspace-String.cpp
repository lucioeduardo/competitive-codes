string proccess(string s){
    string res = s;
    
    int i=0;
    
    for(char c: s){
        if(c!='#'){
            res[i++]=c;
        }else{
            i = max(0, i-1);
        }
    }
    
    return res.substr(0,i);
}


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return proccess(S) == proccess(T);
    }
};