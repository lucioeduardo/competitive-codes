class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        map<int, vector<int>> v;
        map<int, int> idx;
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(!v.count(i-j))
                    v[i-j] = vector<int>();
                v[i-j].push_back(mat[i][j]);
                idx[i-j]=0;
            }
        }
        
        for(auto& p: v){
            sort(p.second.begin(), p.second.end());
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                int u = idx[i-j];
                
                mat[i][j] = v[i-j][u];
                idx[i-j]++;
            }
        }
        
        return mat;
    }
};