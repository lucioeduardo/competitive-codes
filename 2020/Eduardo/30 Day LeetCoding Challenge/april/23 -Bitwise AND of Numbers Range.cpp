class Solution {
public:
    long long rangeBitwiseAnd(long long m, long long n) {
        if(!m || !n) return 0;
        
        
        int a = log2(n);
        int b = log2(m);
        
        if(a != b) return 0;
        
        if(m > n) swap(m,n);
        
        long long int res=m;
        long long int min = (1 << a);
        
        for(long long i=m+1; i<=n; i++){
            res = res&i;
            if(res == min) break;
        }
        
        return res;
    }  
};

class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n > m){
            n -= n & -n; // unsetting the rightmost set bit
        }
        
        return n;
    }
};