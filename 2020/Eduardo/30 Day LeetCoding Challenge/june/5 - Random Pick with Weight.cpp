class Solution {
public:
    vector<int> sum;
    int size=0;
    
    Solution(vector<int>& w) {
        size = w.size();
        
        sum.push_back(w[0]);
        for(int i=1; i<size; i++){
            sum.push_back(w[i] + sum[i-1]);
        }
    }
    
    int pickIndex() {
        int left=0;
        int right=size-1;
        
        int v = 1 + rand()%(sum[right]);        
        
        vector<int>::iterator it = lower_bound(sum.begin(),sum.end(),v);
        
        return (it - sum.begin());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */