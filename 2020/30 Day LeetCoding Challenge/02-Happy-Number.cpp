class Solution {
public:
    bool isHappy(int n) {
        int inic = n;
        int next=0;
        
        set<int> values;
        
        while((values.find(next) == values.end()) && next != 1){
            next=0;
            values.insert(n);
            while(n > 0){
                next += (n%10)*(n%10);
                n/=10;
            }
            n=next;
            printf("%d\n",next);
        }
        
        return (next == 1);
    }
};