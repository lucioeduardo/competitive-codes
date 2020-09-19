class Solution {
public:
    int low,high;
    vector<int> res;
    
    void solve(int num){
        if(num > high) return;
        
        
        if(num >= low && num <= high)
            res.push_back(num);
        
        int d = num%10;
        
        if(d<9) solve(num*10 + (d+1));
    }
    
    vector<int> sequentialDigits(int low, int high) {
        this->low = low;
        this->high = high;
        
        for(int i=1;i<=9;i++) solve(i);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};