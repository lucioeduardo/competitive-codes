class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> res;
        
        for(int num: A){
            if(num % 2 == 0) res.push_back(num);
        }
        
        for(int num: A){
            if(num % 2) res.push_back(num);
        }
        
        return res;
    }
};