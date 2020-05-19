class StockSpanner {
public:
    vector<int> values;
    vector<int> res;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        values.push_back(price);
        int idx = values.size()-2;
        int ret=1;
        
        while(idx >= 0){
            if(values[idx] > price) break;
            ret += res[idx];
            idx -= res[idx];
        }
        
        res.push_back(ret);
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */