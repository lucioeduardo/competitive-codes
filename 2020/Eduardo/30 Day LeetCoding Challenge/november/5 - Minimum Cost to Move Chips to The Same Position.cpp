class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int p=0, i=0;
        
        for(int pos: position){
            if(pos%2) i++;
            else p++;
        }
        
        return min(p,i);
    }
};