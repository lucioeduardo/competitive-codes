class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> p;
        int i=0;
        
        for(int v: pushed){
            p.push(v);
            
            while(!p.empty() && p.top() == popped[i]){
                p.pop();
                i++;
            }
        }
        
        return (i == popped.size());
    }
};