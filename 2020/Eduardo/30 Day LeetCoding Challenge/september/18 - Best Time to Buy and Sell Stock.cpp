class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        
        int m=prices[0];   
        int res=0;
        
        for(int num: prices){
            res = max(res, num-m);
            m = min(num,m); 
        }
        
        return res;
    }
};