#define d 256
const long long q = 1e9+7;

class Solution {
public:
    string longestDupSubstring(string S) {
        string res="";
        int esq=0, dir= S.size();
        
        while(esq <= dir){
            int meio = (esq+dir)/2;
            
            string check = checkSub(S, meio);
            
            if(check.empty()){
                dir = meio-1;
            }else{
                res = check;
                esq = meio+1;
            }
        }
        
        return res;
    }
    
    long long calcHash(string s){
        long long h=0;
        
        for(int i=0; i<s.length(); i++){
            h = ((d*h)%q + s[i])%q;
        }
        
        return h;
    }
    
    long long reHash(long long prev, long long a, long long len, string& S, long long h){
        return (((prev - S[a]*h)*d + S[a+len])%q+q)%q;
    }
    
    string checkSub(string S, int len){
        int n = S.size();
        
        long long p = calcHash(S.substr(0,len));
        
        
        long long h = 1;
        
        for(int i=0; i<len-1; i++){
            h = (h*d)%q;
        }
                
        unordered_map<int, int> seen;
        seen[p]=0;
        
        for(int i=1; i<=n-len; i++){
            
            p = reHash(p,i-1,len,S,h);
            
            if(seen.find(p) != seen.end()){
                bool flag = true;
                int idx = seen[p];
                
                for(int j=0; j<len; j++){
                    if(S[i+j] != S[idx+j]) flag=false;
                }
                
                
                if(flag) return S.substr(i,len);
            }
            
            seen[p] = i;
        }
        
        return "";
    }
};