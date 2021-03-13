#define M 1000000007

class Solution {
public:
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int n=arr.size();
        
        map<int, long long> res;
        
        for(int i=0; i<n; i++){
            int v = arr[i];
            res[v] = 1;
            
            long long s=0;
            for(int j=0; j<i; j++){
                int u = arr[j];
                                
                if(v % u == 0){
                    s += res[u]*res[v/u];
                    s%=M;
                }
            }
                        
            res[v] = (res[v] + s)%M;
        }
        
        int sol=0;
        
        for(int num: arr){
            sol = (sol + res[num])%M;
        }
        
        return sol;
    }
};