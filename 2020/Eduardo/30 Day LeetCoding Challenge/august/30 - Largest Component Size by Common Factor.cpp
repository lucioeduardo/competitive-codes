#define MAXN 100010

class Solution {
public:
    int pai[MAXN];
    
    int find(int a){
        if(a == pai[a]) return a;
        return pai[a] = find(pai[a]);
    }
        
    void join(int a, int b){
        int fa=find(a), fb=find(b);
        
        pai[fa] = pai[fb];
    }
        
    int largestComponentSize(vector<int>& A) {                
        for(int i=0; i<MAXN; i++){
            pai[i]=i;
        }
        
        for(int i=0; i<A.size(); i++){
            for(int k=2; k*k<=A[i]; k++){
                if(A[i] % k == 0){
                    join(A[i],k);
                    join(A[i],A[i]/k);
                }
            }
        }
        
        int res=0;
        map<int,int> count;
        
        for(int i=0; i<A.size(); i++){
            res = max(res, ++count[find(A[i])]);
        }
        
        
        return res;
    }
};