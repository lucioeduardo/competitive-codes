int sX[4]={0,1,0,-1};
int sY[4]={1,0,-1,0};

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int idx=0;
        
        for(int i=0;i<4; i++){
            for(char c: instructions){
                if(c == 'R') idx++;
                else if(c == 'L') idx--;
                else{
                    x += sX[idx];
                    y += sY[idx];
                }

                idx = (idx+4)%4;
            }
        }
        
        
        return (x == 0 && y == 0);
    }
};