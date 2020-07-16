class Solution {
public:
    double myPow(double x, long long n) {
        if(x == 1) return 1;
        
        bool flag = (n < 0);
        if(flag) n=-n;
        
        double res=1;
        while(n>0){
            if(n%2)
                res *= x;
            x = (x*x);
            n/=2;
        }
        
        if(flag) res = 1/res;
        
        return res;
    }
};