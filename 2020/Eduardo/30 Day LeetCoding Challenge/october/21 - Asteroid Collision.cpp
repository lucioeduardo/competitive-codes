class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res(asteroids.size(),0);
        int r=-1;
        
        for(int num: asteroids){
            //cout << r << endl;
            if(r >= 0 && (sign(res[r]) && !sign(num))){
                bool f = true;
                while(f && r >= 0 && (sign(res[r]) && !sign(num))){
                    if(abs(num) > abs(res[r])) r--;
                    else if(abs(num) == abs(res[r])){
                        r--;
                        f=false;
                    }
                    else f=false;
                }
                if(f) res[++r]=num;
            }else{
                res[++r]=num;
            }   
        }
        
        return vector<int>(res.begin(),res.begin()+r+1);
    }
    
    bool sign(int v){
        if(v < 0) return false;
        return true;
    }
};