class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        
        int f[26],l[26];
        for(int i=0; i<26; i++){
            f[i]=0;
            l[i]=999999;
        }
        
        for(int i=0; i<S.length(); i++){
            int c = S[i]-'a';
            
            f[c] = min(f[c], i);
            l[c] = max(f[c],i);
        }
        
        int esq=0, dir=0;
        
        for(int i=0; i<S.length(); i++){
            int c = S[i]-'a';
            dir = max(dir, l[c]);
            
            if(dir == i){
                res.push_back(dir-esq+1);
                esq=i+1;
                dir=i+1;
            }
        }
        
        return res;
    }
};