class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int x=newInterval[0], y=newInterval[1];
        
        int actX=-1, actY=-1;
        bool flag=true;
        
        for(vector<int> v: intervals){
            int a = v[0], b=v[1];
            
            if(actX == -1 && x <= b) actX=a;
            if(actX != -1 && y >= a) actY=b;
            
            cout << actX << " " << actY << endl;
            
            if(x > b || a > y){
                if(flag && actX != -1) {
                    res.push_back({min(x,actX),max(y,actY)});
                    flag=false;
                }
                
                res.push_back({a,b});
            }
            
        }
                
        if(actX == -1){
            actX = x;
            actY = y;
        }
        
        if(flag) {
            res.push_back({min(x,actX),max(y,actY)});
            flag=false;
        }
        
        return res;
    }
};