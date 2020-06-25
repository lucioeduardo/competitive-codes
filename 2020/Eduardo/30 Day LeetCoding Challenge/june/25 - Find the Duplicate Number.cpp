class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int turtoise = nums[0];
        int hare = nums[0];
        
        do{
            turtoise = nums[turtoise];
            hare = nums[nums[hare]];
        }while(turtoise != hare);
        
        turtoise = nums[0];
        
        while(turtoise != hare){
            turtoise = nums[turtoise];
            hare = nums[hare];
        }
        
        return turtoise;
    }
};