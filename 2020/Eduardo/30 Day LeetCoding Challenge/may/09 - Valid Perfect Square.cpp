class Solution {
public:
    bool isPerfectSquare(int num) {
        int esq = 0, dir = num;
        
        while(esq <= dir){
            long long meio = (esq+dir)/2;
            
            if(meio*meio == num){
                return true;
            }
            
            if(meio*meio < num)
                esq = meio+1;
            else
                dir = meio-1;
        }
        
        return false;
    }
};