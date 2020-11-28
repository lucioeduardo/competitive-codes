class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
            
        for(int i=0; i<k; i++){
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        
        res.push_back(nums[q.front()]);
        
        for(int i=1; i<nums.size()-k+1; i++){
            while(!q.empty() && q.front() < i) q.pop_front();
            
            int next = i+k-1;
            
            if(next < nums.size()){
                while(!q.empty() && nums[q.back()] < nums[next])
                    q.pop_back();
                q.push_back(next);
            }
            
            res.push_back(nums[q.front()]);
        }
        
        return res;
    }
};