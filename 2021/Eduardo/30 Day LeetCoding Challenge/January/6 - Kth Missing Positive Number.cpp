class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int p=0;
        int q=0;
        
        for(int num: arr){
            int s = num-p-1;
            
            if(q + s >= k){
                return p + (k-q);
            }
            
            p=num;
            
            q += s;
        }
        
        return arr[arr.size()-1] + (k-q);
    }
};