class Solution {
public:
    int mirrorReflection(int p, int q) {
        bool u=true, r=true;
        int d = p;
        
        while(true){
            d -= q;
            if(!d){
                if(u) return r ? 1 : 2;
                else if(r) return 0;
            }
            
            if(d < 0){
                d = d+p;
                u = !u;
            }
            
            r = !r;
        }
        
    }
};