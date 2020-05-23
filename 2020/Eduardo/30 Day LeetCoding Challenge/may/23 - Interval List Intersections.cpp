class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int idxA=0, idxB=0;
        
        vector<vector<int>> res;
        
        while(idxA < A.size() && idxB < B.size()){
            int l1,r1,l2,r2;
            
            l1 = A[idxA][0];
            r1 = A[idxA][1];
            
            l2 = B[idxB][0];
            r2 = B[idxB][1];
            
            if(!(l1 > r2 || r1 < l2)){
                int a = max(l1,l2);
                int b = min(r1,r2);
                
                vector<int> add = {a,b};
                res.push_back(add);
                
            }
            
            if(r1 > r2) idxB++;
            else idxA++;
        }
        
        return res;
    }
};