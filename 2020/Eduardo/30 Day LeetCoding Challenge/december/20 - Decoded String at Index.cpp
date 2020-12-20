class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long n=0;
        for(char c: S){
            if(isdigit(c))
                n*=(c-'0');
            else
                n++;
        }
        
        
            
        for(int i=S.size()-1; i>=0; i--){
            K %= n;
            
            if(K == 0 && !isdigit(S[i]))
                return (string)""+S[i];
            
            if(isdigit(S[i]))
                n/=(S[i]-'0');
            else
                n--;
        }
            
        return "a";
    }
};