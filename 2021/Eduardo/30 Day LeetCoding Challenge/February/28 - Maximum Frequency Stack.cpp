#define pii pair<int,int>


struct node{
    int v, f, idx;
};

class Compare
{
public:
    bool operator() (node a, node b)
    {
        if(a.f == b.f)
            return a.idx < b.idx;
        return a.f < b.f;
    }
};


class FreqStack {
public:
    map<int, int> freq;
    priority_queue<node, vector<node>, Compare> pq;
    int i;
    
    FreqStack() {
        freq.clear();
        i=0;
    }
    
    void push(int x) {
        freq[x]++;
        pq.push({x, freq[x], i});
        i++;
    }
    
    int pop() {
        node top = pq.top();
        freq[top.v]--;
        pq.pop();
        
        
        return top.v;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */