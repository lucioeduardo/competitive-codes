#define MAXN 110
int v[MAXN];
bool compare(int a, int b){
    if(v[a] == v[b])
        return a<b;
    return v[a]<v[b];
}

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        
        vector<int> ord;
        
        for(int i=0; i<n; i++){
            ord.push_back(i);
            v[i]=0;
            for(int j=0; j<mat[i].size(); j++){
                v[i] += mat[i][j];
            }
        }
        
        sort(ord.begin(), ord.end(), compare);
        
        vector<int> res(ord.begin(), ord.begin()+k);
        
        return res;
    }
};