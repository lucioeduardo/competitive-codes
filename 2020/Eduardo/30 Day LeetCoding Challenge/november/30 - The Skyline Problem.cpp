int getLast(vector<vector<int>>& v){
    if(v.empty()) return -1;
    return v[v.size()-1][1];
}

class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& buildings, int a, int b){
        //cout << a << " " << b << endl;
        if(a == b){
            vector<vector<int>> res;
            //cout << "alo" << " " << a << " " << b << " " << res.size() << endl;
            
            int x = buildings[a][0], r = buildings[a][1], h = buildings[a][2];
            
            res.push_back({x, h});
            res.push_back({r,0});
            
            //cout << "alo" << " " << a << " " << b << " " << res.size() << endl;
            
            return res;
        }
        
        int m = (a+b)/2;
        
        vector<vector<int>> v1 = solve(buildings, a,m);
        vector<vector<int>> v2 = solve(buildings, m+1,b);
        
        vector<vector<int>> res;
        
        int it1=0, it2=0;
        int h1=0, h2=0;
        
        //cout << "alo" << " " << a << " " << b << " " << v1.size() << " " << v2.size() << endl;
        
        while(it1 < v1.size() && it2 < v2.size()){
            int x1=v1[it1][0];
            int x2=v2[it2][0];
            
            //cout << x1 << " -> " << x2 << endl;
            
            if(x1 == x2){
                h1=v1[it1][1];
                h2=v2[it2][1];
                
                if(getLast(res) != max(h1,h2)) res.push_back({x1,max(h1,h2)});
                it1++;it2++;
            }else if(x1 < x2){
                h1 = v1[it1][1];
                if(getLast(res) != max(h1,h2)) res.push_back({x1,max(h1,h2)});
                it1++;
            }else{
                h2 = v2[it2][1];
                if(getLast(res) != max(h1,h2)) res.push_back({x2,max(h1,h2)});
                it2++;
            }
        }
        
        while(it1 < v1.size()){
            int x1=v1[it1][0];
            h1 = v1[it1][1];
                        
            if(getLast(res) != max(h1,h2)) res.push_back({x1,max(h1,h2)});
            it1++;
        }
        
        while(it2 < v2.size()){
            int x2=v2[it2][0];
            h2 = v2[it2][1];
            if(getLast(res) != max(h1,h2)) res.push_back({x2,max(h1,h2)});
            it2++;
        }
        
        v1.clear();
        v2.clear();
        
        return res;
    }
    
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.size() == 0) return vector<vector<int>>();
        return solve(buildings, 0, buildings.size()-1);
    }
};