class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0, act=0;
        
        for(char c: s){
            cout << res << endl;
            
            if(c == ' '){
                if(act) res=act;
                act=0;
            }
            else
                act++;
        }
        
        return act ? act : res;
    }
};