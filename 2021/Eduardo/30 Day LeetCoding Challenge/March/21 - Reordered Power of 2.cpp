class Solution {
public:
    
    bool comp(int a, int b){
        int freq[10];
        memset(freq,0,sizeof(freq));
        
        while(a > 0){
            freq[a%10]++;
            a /=10;
        }
        
        while(b > 0){
            freq[b%10]--;
            b /=10;
        }
        
        for(int x: freq){
            if(x != 0) return false;
        }
        
        return true;
    }
    
    bool reorderedPowerOf2(int N) {
        for(int i=0; i<32; i++){
            if(comp(N, 1<<i))
                return true;
        }
        
        return false;
    }
};