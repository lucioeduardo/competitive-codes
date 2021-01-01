class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        
        bool f = true;
        
        for(vector<int> v: pieces){
            int i=0, idx=-1;
            for(int j=0; j<n; j++){
                if(v[i] == arr[j]){
                    idx=j;
                    break;
                }
            }
            
            if(idx == -1) return false;
            
            for(i=0; i<v.size(); i++){
                if(idx == n || v[i] != arr[idx++])
                    return false;
            }
            
        }
        
        return true;
    }
};