class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int max=0;
        
        for(int i=0; i<s; i++){
            if(flowerbed[i]) continue;
            bool f=true;
            
            if(i > 0 && flowerbed[i-1])
                f=false;
            if(i < s-1 && flowerbed[i+1])
                f=false;
            
            if(f) flowerbed[i]=1;
            
            max += f;
        }
        
        return (n <= max);
    }
};