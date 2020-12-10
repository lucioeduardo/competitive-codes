class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;
        
        if(arr[0] > arr[1]) return false;
        bool inc=true;
        
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]) return false;
            
            if(arr[i] < arr[i-1]){
                if(inc) inc=false;
            }else{
                if(!inc) return false;
            }
        }
        
        return (inc == false);
    }
};