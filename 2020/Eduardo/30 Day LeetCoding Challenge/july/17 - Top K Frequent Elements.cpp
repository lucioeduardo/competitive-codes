unordered_map<int,int> cnt;

bool compare(int a, int b){
    return cnt[a] > cnt[b];
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> keys;
        cnt.clear();
        
        if(nums.size() == k) return nums;
        
        
        for(int num: nums){
            if(cnt.find(num) == cnt.end()){
                cnt[num] = 0;
                keys.push_back(num);
            }
            cnt[num]++;
        }
        
        sort(keys.begin(), keys.end(), compare);
        
        vector<int> res;
        
        for(int i=0; i<k; i++)
            res.push_back(keys[i]);
        
        return res;
    }
};