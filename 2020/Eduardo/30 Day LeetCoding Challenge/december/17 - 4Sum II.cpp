class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> sums;
        
        for(int x: A){
            for(int y: B){
                sums[x+y]++;
            }
        }
        
        long long res = 0;
        
        for(int x: C){
            for(int y: D){
                res += sums[-(x+y)];
            }
        }
        
        return res;
    }
};