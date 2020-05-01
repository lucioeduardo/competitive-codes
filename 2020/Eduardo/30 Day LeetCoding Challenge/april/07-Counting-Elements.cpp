#define MAXV 1010

class Solution {
public:
    int countElements(vector<int>& arr) {
        bool exist[MAXV];
        memset(exist,false,sizeof(exist));
        
        for(int num: arr){
            exist[num]=true;
        }
        
        int res=0;
        
        for(int num: arr){
            if(exist[num+1]) res++;
        }
        
        return res;
    }
};