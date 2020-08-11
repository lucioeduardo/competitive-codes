class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        
        int esq=0, dir=n;
        int res=0;
        
        while(esq <= dir){
            int meio = (esq+dir)/2;
            
            int v = (lower_bound(citations.begin(), citations.end(), meio))-citations.begin();
                                    
            if(n-v >= meio){
                res = meio;
                esq = meio+1;
            }else{
                dir = meio-1;
            }
        }
        
        return res;
    }
};