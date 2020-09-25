string toStr(int n){
    if(n == 0) return "0";
    string res="";
    while(n>0){
        res += '0'+(n%10);
        n/=10;
    }
    
    reverse(res.begin(),res.end());
    return res;
}

bool compare(string a, string b){
    string ab = a+b;
    string ba = b+a;
    
    return ab > ba;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        
        bool f=true;
        
        for(int num: nums){
            if(num != 0) f=false;
            strs.push_back(toStr(num));
        }
        
        if(f) return "0";
        
        sort(strs.begin(), strs.end(), compare);
        
        string res="";
        
        for(string s: strs){
            res += s;
        }
        
        
        return res;
    }
};