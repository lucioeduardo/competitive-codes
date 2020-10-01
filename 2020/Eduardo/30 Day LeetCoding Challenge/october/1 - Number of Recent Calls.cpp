class RecentCounter {
public:
    vector<int> requests;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        requests.push_back(t);
        
        vector<int>::iterator it = lower_bound(requests.begin(), requests.end(), t-3000);
        
        return (requests.end()-it);
    }
};