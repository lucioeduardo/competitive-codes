

class Solution {
public:
    
    bool matches(string a, string b){
        if(a.size() != b.size()) return false;
        bool f=false;
        
        for(int i=0; i<a.size(); i++){
            if(a[i] != '*') f=true;
            if(a[i] != '*' && a[i] != b[i])
                return false;
        }
        
        return f;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.size();
        vector<int> res;
        bool f=true;
        int c=0;
        
        while(f && c < target.size()){
            f=false;
            for(int i=0; i<target.size(); i++){
                if(target[i] == stamp[0] || target[i] == '*'){
                    if(matches(target.substr(i,n),stamp)){
                        f=true;
                        
                        res.push_back(i);
                        
                        for(int j=0; i+j<target.size() && j<n; j++){
                            if(target[i+j] != '*') c++;
                            target[i+j]='*';
                        }
                    }
                }
            }
        }
        
                
        reverse(res.begin(), res.end());
        
        if(c != target.size()) res.clear();
        
        return res;
    }
};