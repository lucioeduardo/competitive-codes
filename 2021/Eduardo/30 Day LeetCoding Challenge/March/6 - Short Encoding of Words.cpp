bool compare(string& a, string& b){
    return a.length() > b.length();
}

class Solution {
public:
    bool isSuffix(string& a, string& b){
        int idx_a=a.length()-1, idx_b = b.length()-1;
        
        while(idx_a >= 0 && a[idx_a] == b[idx_b]){
            idx_a--;
            idx_b--;
        }
        
        return idx_a < 0;
    }
    
    
    int minimumLengthEncoding(vector<string>& words) {
        
        sort(words.begin(), words.end(), compare);
        
        vector<string> add;
        int res=0;
        
        for(string s: words){
            bool flag=true;
            for(string x: add){
                if(isSuffix(s,x))
                    flag=false;
                if(!flag) break;
            }
            
            if(flag){
                add.push_back(s);
                res += s.size()+1;
            }
        }
        
        return res;
    }
};