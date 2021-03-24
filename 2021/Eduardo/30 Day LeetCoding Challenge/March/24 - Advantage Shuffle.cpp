class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        vector<int> copy = B;
        vector<int> resto;
        sort(copy.begin(),copy.end());
        
        int idxA=0, lA=0;
        int n = A.size();
        
        map<int, stack<int>> p;
        
        for(int i=0; i<n; i++){
            while(idxA < n && A[idxA] <= copy[i]){
                resto.push_back(A[idxA]);
                idxA++;
                
            }
            
            //cout << idxA <<  " " << copy[i] << endl;
            
            if(idxA < n)
                p[copy[i]].push(A[idxA++]);
            else
                p[copy[i]].push(resto[lA++]);
                
        }
        
        vector<int> res;
        
        for(int i: B){
            res.push_back(p[i].top());
            p[i].pop();
        }
        
        return res;
    }
};