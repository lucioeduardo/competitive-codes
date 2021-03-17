#include <math.h>

double randZeroToOne()
{
    return rand() / (RAND_MAX + 1.);
}

class Solution {
public:
    
    double r,x,y;    
    
    Solution(double radius, double x_center, double y_center) {
        this->r = radius;
        this->x = x_center;
        this->y = y_center;
    }
    
    vector<double> randPoint() {

        
        double h = sqrt(randZeroToOne())*r;
        double angle = randZeroToOne()*M_PI*2;
                
        return {x+ h*cos(angle), y + h*sin(angle)};

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */