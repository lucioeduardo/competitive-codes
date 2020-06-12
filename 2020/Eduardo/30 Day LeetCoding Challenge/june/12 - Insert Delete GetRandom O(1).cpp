class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> valuesMap;
    vector<int> values;
    
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(valuesMap.find(val) != valuesMap.end()) return false;
        valuesMap[val]=values.size();
        values.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_map<int,int>::iterator it = valuesMap.find(val);
        if(it == valuesMap.end()) return false;
        int idx = it->second;
        valuesMap.erase(it);
        
        int end = values.size()-1;
        if(idx != end) valuesMap[values[end]]=idx;
        swap(values[idx], values[end]);
        values.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        int end = values.size();
        
        int r = rand()%end;
        
        return values[r];
    }
    
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */