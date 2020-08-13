class CombinationIterator {
public:
    vector<string> combs;
    int act = 0;
    
    CombinationIterator(string characters, int combinationLength) {
        int n = characters.length();
        combs.clear();
        
        for(int i=1; i<(1<<n); i++){
            if(__builtin_popcount(i) == combinationLength){
                string s = "";
                for(int j=0; j<n; j++){
                    if((1 << j) & i)
                        s += characters[j];
                }
                combs.push_back(s);
            }
        }
        
        
        sort(combs.begin(), combs.end());
    }
    
    string next() {
        return combs[act++];
    }
    
    bool hasNext() {
        return act < combs.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */