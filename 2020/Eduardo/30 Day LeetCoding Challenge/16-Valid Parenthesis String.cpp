class Solution {
public:
    bool checkValidString(string s) {
        int n_brack=0;
        bool flag=true;

        int idx[110];
        
        int i=0;
        
        for(char c: s){
            if(c == '('){
                idx[n_brack++]=i;
            }else if(c == ')'){
                if(n_brack > 0){
                    s[idx[--n_brack]] = 'x';
                    s[i]='x';
                }
            }
            i++;
        }
        
        int n_ast=0;
        
        for(char c: s){
            if(c == '*'){
                n_ast++;
            }else if(c == ')'){
                if(n_ast){
                    n_ast--;
                }else{
                    flag=false;
                }
            }
        }
        
        n_ast=0;
        
        for(int i=s.length()-1; i>=0 ; i--){
            if(s[i] == '*'){
                n_ast++;
            }else if(s[i] == '('){
                if(n_ast){
                    n_ast--;
                }else{
                    flag=false;
                }
            }
        }
                        
        return flag;
    }
};

//(()())