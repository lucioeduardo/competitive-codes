bool compare(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}
    

class Solution {
public:

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res(people.size());
        
        set<int> positions;
        
        sort(people.begin(), people.end(), compare);
        
        for(vector<int> person: people){
            int a=person[0], b=person[1];
            
            for(int pos: positions){
                if(pos <= b && res[pos][0] < a) b++;
            }
            
            positions.insert(b);
            res[b] = person;
        }
        
        return res;
    }
};