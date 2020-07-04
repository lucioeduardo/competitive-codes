#define ll long long

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        vector<ll> seq;
        
        q.push(1); 
        
        while(seq.size()<n){
            ll t = q.top(); q.pop();
            
            if(!seq.empty() && t == seq.back()) continue;
            
            seq.push_back(t);
            
            q.push(t*2);
            q.push(t*3);
            q.push(t*5);
        }
        
        return seq[n-1];
    }
};