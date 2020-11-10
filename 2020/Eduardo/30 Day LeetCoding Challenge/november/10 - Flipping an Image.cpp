class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        
        for(vector<int> &v : A){
            vector<int> new_vec;
            for(int i=v.size()-1; i>=0; i--){
                new_vec.push_back(!v[i]);
            }
            res.push_back(new_vec);
        }
        
        return res;
    }
};