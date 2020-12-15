class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sorted;
        
        for(int num: nums){
            sorted.push_back(num*num);
        }
        
        sort(sorted.begin(), sorted.end());
        
        return sorted;
    }
};