class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> types;
        
        for(int v: candyType){
            types.insert(v);
        }
        
        return min(candyType.size()/2, types.size());
    }
};