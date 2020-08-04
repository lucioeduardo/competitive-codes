class Solution {
public:
    bool isPowerOfFour(int num) {
        bool res = true;
        int c=0;
        
        for(int i=0; i<32; i++){
            if(1<<i & num){
                if(i%2==0)c++;
                else res=false;
            }
        }
                
        return res && (c == 1);
    }
};