class FirstUnique {
public:
    int idx, n;
    unordered_map<int,int> qtd;
    vector<int> nums;
    
    FirstUnique(vector<int>& nm) {
        idx=0;
        n = nums.size();
        nums = nm;
        
        for(int num : nums){
            qtd[num]++;
        }
        
    }
    
    int showFirstUnique() {
        while(idx < nums.size() && qtd[nums[idx]] > 1) idx++;
        
        return idx == nums.size() ? -1 : nums[idx];
    }
    
    void add(int value) {
        if(qtd[value]>1) return;
        
        nums.push_back(value);
        qtd[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */