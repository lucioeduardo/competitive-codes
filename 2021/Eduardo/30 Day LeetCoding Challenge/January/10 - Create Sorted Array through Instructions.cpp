#define ll long long
#define MAXN 100100
#define MOD 1000000007

ll bit[MAXN];
int n;


ll sum(int v){
    int idx=v+1;
    ll res=0;
    
    while(idx > 0){
        res += bit[idx];
        idx -= (idx)&(-idx);
    }
    
    return res;
}

void update(int v){
    int idx = v+1;
    while(idx <= n){
        //cout << idx << " (upd)--> " << bit[idx] << endl;
        bit[idx]++;
        idx += (idx)&(-idx);
    }
}


class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        n = 0;
        map<int,int> qtd;
        
        for(int i=0;i<instructions.size();i++){
            n = max(n,instructions[i]+1);
        }
        
        cout << n << endl;
        
        for(int i=0; i<=n; i++) bit[i]=0;
        
        ll res=0;
                
        for(int i=0; i<instructions.size(); i++){
            int v = instructions[i];
            
            qtd[v]++;
            
            int q = sum(v-1);
            int k = max(0, i-q-(qtd[v]-1));
            
            
            if(min(q,k) < 0)
                cout << min(q,k) << endl;            
            
            
            res += min(q, k);
            
            update(v);
        }
        
        return res%MOD;
    }
};