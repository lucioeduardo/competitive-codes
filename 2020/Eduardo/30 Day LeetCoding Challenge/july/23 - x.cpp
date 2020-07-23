//O(n) space
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> q;
        
        for(int num: nums){
            q[num]++;
        }
        
        vector<int> res;
        
        for(int num: nums){
            if(q[num] == 1) res.push_back(num);
        }
        
        return res;
    }
};

//O(1) space
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int all_xor=0;
        
        for(int num: nums){
            all_xor ^= num;
        }
        
        int bit=0;
        
        while(!((1<<bit) & all_xor))
            bit++;
        
        int a=0, b=0;
        
        for(int num: nums){
            if(num & (1<<bit))
                a ^= num;
            else
                b ^= num;
        }
        
        return {a,b};
    }
};