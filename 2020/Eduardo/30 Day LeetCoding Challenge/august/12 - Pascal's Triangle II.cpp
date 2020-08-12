class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int ant[40], act[40];
        memset(ant,0,sizeof(ant));
        memset(act,0,sizeof(act));
        
        ant[0]=1;
        act[0]=act[1]=1;
        
        for(int i=2; i<=rowIndex; i++){
            copy(begin(act),end(act),begin(ant));
            
            act[0] = act[rowIndex] = 1;
            for(int j=1;j<rowIndex; j++){
                act[j] = ant[j-1] + ant[j];
            }
        }
        
        return vector<int> (act, act+rowIndex+1);
    }
};