class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0;
        
        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                secret[i]='x';
                guess[i]='x';
                a++;
            }
        }
        
        sort(secret.begin(), secret.end());
        sort(guess.begin(), guess.end());
                
        int iS=0, iG=0;
        
        int b=0;
        
        while(iS < secret.length() && iG < guess.length()){
            if(secret[iS] == 'x' || guess[iG] == 'x')
                break;
            
            char c = secret[iS], d = guess[iG];
            
            if(c == d){
                b++;
                iS++;iG++;
            }else if(c < d){
                iS++;
            }else iG++;
        }
        
        string res = to_string(a) + "A" + to_string(b) + "B";
        
        return res;
    }
};