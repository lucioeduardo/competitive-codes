class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        
        int it=0, q=1;
        
        while(candies >= q){
            res[it++] += q;
            candies -= q;
            
                        
            if(it == num_people) it = 0;
            q++;
        }
        
        res[it] += candies;
        
        return res;
    }
};