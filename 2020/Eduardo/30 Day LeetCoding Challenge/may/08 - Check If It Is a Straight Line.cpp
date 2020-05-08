class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        pair<int,int> v = build_vet(coordinates[0],coordinates[1]);
        
        for(int i=2; i<coordinates.size(); i++){
            pair<int,int> v2 = build_vet(coordinates[0],coordinates[i]);
            
            if(v.first*v2.second != v.second*v2.first)
                return false;
        }
        
        return true;
    }
    
    pair<int,int> build_vet(vector<int>&a, vector<int>&b){
        int x = abs(b[0]-a[0]);
        int y = abs(b[1]-a[1]);
            
        return {x,y};
    }
    
};