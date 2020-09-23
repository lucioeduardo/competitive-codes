// O(n^2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int res=-1;
        
        for(int i=0; i<n && res == -1; i++){
            int sum = gas[i]-cost[i];
            bool f = true;
            if(sum < 0) f=false;
            for(int j=(i+1)%n; j!=i && f; j=(j+1)%n){
                sum += (gas[j]-cost[j]);
                if(sum < 0) f=false;
                
            }
            
            if(f) res=i;
        }
        
        return res;
    }
};

// O(n)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int q=0, d=0;
        int idx=0;
        
        for(int i=0;i<n; i++){
            q += gas[i]-cost[i];
            
            if(q<0){
                d += q;
                idx=i+1;
                q=0;
            }
        }
        

        return (q + d >= 0) ? idx : -1;
    }
};