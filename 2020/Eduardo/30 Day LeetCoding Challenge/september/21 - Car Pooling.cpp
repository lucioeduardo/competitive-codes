#define MAXN 1010

class Solution {
public:
    int cap[MAXN];
    
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for(int i=0;i<MAXN;i++) cap[i]=0;
        
        for(vector<int> v: trips){
            int c=v[0];
            int a=v[1];
            int b=v[2];
            
            cap[a]+=c;
            cap[b]-=c;
        }
        
        int it=0;
        
        for(int i=0;i<MAXN; i++){
            it += cap[i];
            if(it > capacity) return false;
        }
        
        return true;
    }
};