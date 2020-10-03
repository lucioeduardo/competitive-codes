class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res=0;
        
        if(k == 0){
            unordered_map<int,int> m;
            for(int num: nums){
                m[num]++;
            }
            
            for(auto& [k,v] : m){
                if(v >= 2) res++;
            }
        }else{
            unordered_set<int> s;
        
            for(int num: nums){
                s.insert(num);
            }



            for(int num: s){
                if(s.count(num+k)) res++;
            }
        }
        
        
        
        return res;
    }
};