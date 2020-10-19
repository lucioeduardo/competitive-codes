class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int count[7], cA[7], cB[7];
        
        for(int i=1; i<=6; i++) cA[i] = cB[i] = count[i] = 0;
        
        for(int i=0; i<A.size(); i++){
            int x = A[i], y = B[i];
            
            cA[x]++;
            cB[y]++;
            
            if(x == y) count[x]++;
            else{
                count[x]++;
                count[y]++;
            }
        }
        
        int res=-1;
        int n = A.size();
        
        for(int i=1; i<=6; i++){
            if(count[i] == n){
                int m = min(n-cA[i],n-cB[i]);
                
                if(m < res || res == -1) res = m;
            }
        }
        
        return res;
    }
};