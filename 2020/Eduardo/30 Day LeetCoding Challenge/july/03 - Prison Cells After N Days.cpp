class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        string s = "x";
        
        for(int i=0; i<8; i++){
            s += ('0'+cells[i]);
        }
        s+='x';
        
        vector<string> seq;
        map<string, int> idx;
                
        while(idx.find(s) == idx.end()){
            idx[s] = seq.size();
            seq.push_back(s);
            s = proc(s);
        }
        
        int ini = idx[s];
        int size = seq.size()-ini;
        
                
        string res = seq[ini+((N-ini)%size)];
        
        vector<int> sol;
        
        for(int i=1; i<=8; i++)
            sol.push_back(res[i]-'0');
        
        return sol;
    }
    
    string proc(string s){
        string res = s;
        for(int i=1; i<s.length()-1; i++){
            if(s[i-1] == s[i+1]) res[i]='1';
            else res[i]='0';
        }
        return res;
    }
};