class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int qtd[N+1];
        for(int i=1; i<=N; i++) qtd[i]=0;
        
        for(vector<int> p: trust){
            qtd[p[1]]++;
            qtd[p[0]]=-99999;
        }
        
        int res=-1;
        
        for(int i=1; i<=N; i++){
            if(qtd[i] == N-1 && res != -1) return -1;
            if(qtd[i] == N-1) res=i;
        }
        
        return res;

    }
};