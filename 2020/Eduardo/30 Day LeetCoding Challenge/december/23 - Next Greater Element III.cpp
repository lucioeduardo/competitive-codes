class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        
        int k=n;
        
        while(k > 0){
            int d = k%10;
            k/=10;
            
            digits.push_back(d);
        }
        
        reverse(digits.begin(), digits.end());
        
        int size = digits.size();
        
        int v=size-1;
        
        bool flag = false;
        
        for(int i=size-2; i>=0 && !flag;i--){
            if(digits[i] < digits[i+1]){
                flag = true;
                v=i;
            }
        }
        
        if(!flag) return -1;
        
        int sw=v+1;
        for(int i=v+1; i<size; i++){
            if(digits[i] <= digits[v]) continue;
            
            if(digits[i] < digits[sw]) sw=i;
        }
        
        swap(digits[v], digits[sw]);
        
        sort(digits.begin()+v+1, digits.end());
        
        
        long long res = 0, pot=1;
        
        for(int i=size-1; i>=0; i--){
            res += digits[i]*pot;
            pot*=10;
        }
        
        return res <= INT_MAX ? res : -1;
    }
};