class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = people.size();
        
        int r = upper_bound(people.begin(), people.end(), limit-people[0]) - people.begin();
        
                
        for(int i=0; i<people.size(); i++){
            r--;
            while(r > i){
                if(people[r] + people[i] <= limit){
                    res--;
                    break;
                }
                r--;
            }
        }
        
        return res;
    }
};