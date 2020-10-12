class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        
        int x=-1,y=-1;
        
        for(int i=0; i<A.size(); i++){
            if(A[i] != B[i]){
                if(x == -1) x = i;
                else if(y == -1) y=i;
                else return false;
            }
        }
        
        if(x != -1 && y != -1) swap(A[x],A[y]);
        else{
            map<char,int> q;
            bool f=false;
            
            for(char c: A){
                q[c]++;
                if(q[c] > 1) f=true;
            }
            
            if(!f) return false;
        }
        
        
        
        return A == B;
    }
};