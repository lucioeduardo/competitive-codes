class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int qtd=0;
        int n = A.size();
        vector<int> res;
        
        while(qtd < A.size()){
            int m=0;
            for(int i=0; i<n-qtd; i++){
                if(A[i] > A[m])
                    m = i;
            }
            
            
            if(m != 0) res.push_back(m+1);
            if(n-qtd != 1) res.push_back(n-qtd);
            
            reverse(A.begin(), A.begin()+m+1);
            reverse(A.begin(), A.begin()+(n-qtd));
            
            qtd++;
        }
        
        return res;
        
    }
    
    
};