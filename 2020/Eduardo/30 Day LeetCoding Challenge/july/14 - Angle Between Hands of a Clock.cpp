class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hAng = (hour*30.0) + minutes*0.5;
        double mAng = (minutes*6);
        
        double ang = abs(hAng-mAng);
        
        return min(ang,360-ang);
    }
};