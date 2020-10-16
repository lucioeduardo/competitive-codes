class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> lines;
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        if(m == 0) return false;
        
        for(int i=0; i<n; i++)
            lines.push_back(matrix[i][0]);
        
        int idx = upper_bound(lines.begin(),lines.end(),target) - lines.begin() - 1;
        if(idx < 0) return false;
        
        vector<int>::iterator it = lower_bound(matrix[idx].begin(), matrix[idx].end(), target);
        
        return (it != matrix[idx].end() && *it == target);
    }
};