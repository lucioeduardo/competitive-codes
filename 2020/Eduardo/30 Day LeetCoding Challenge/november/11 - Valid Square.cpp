class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2){
        return pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1],2);
    }
    
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1,p2,p3,p4};
        int l=-1;
        
        int a = dist(p1,p2);
        int b = dist(p1,p3);
        int c = dist(p1,p4);
        
        if(a == b || a == c) l = a;
        else l = b;
        
        
        bool res = true;
        
        for(int i=0; i<4; i++){
            int cont=0;
            bool f=false;
            
            for(int j=0; j<4; j++){
                if(j == i) continue;
                
                int d = dist(points[i], points[j]);
                
                if(d == l) cont++;
                else if(d == 2*l) f=true;
            }
            
            if(cont != 2 || !f) res=false;
        }
        
        return res;
    }
};