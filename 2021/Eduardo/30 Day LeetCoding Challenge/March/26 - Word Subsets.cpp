class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int n = B.size();
        
        int freq[n][26], freq_max[26];
        memset(freq,0,sizeof(freq));
        memset(freq_max,0,sizeof(freq_max));
        
        for(int i=0; i<n; i++){
            string s = B[i];
            for(char c : s){
                freq[i][c-'a']++;
                
                freq_max[c-'a'] = max(freq_max[c-'a'] , freq[i][c-'a']);
            }
        }
        
        vector<string> res;
        
        for(string s: A){
            int f[26];
            memset(f,0,sizeof(f));
            for(char c: s){
                f[c-'a']++;
            }
            
            bool flag=true;
            
            //cout << "\n\n" <<  s << endl;
            for(int i=0; i<26; i++){
                //cout << f[i] << " " << freq_max[i] << endl;
                if(f[i] < freq_max[i]) flag=false;
            }
            
            if(flag) res.push_back(s);
        }
        
        return res;
    }
};