class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> fila;
        
        for(int num: stones){
            fila.push(num);
        }
        
        while(fila.size() > 1){
            int a = fila.top(); fila.pop();
            int b = fila.top(); fila.pop();
            
            if(a != b){
                fila.push(a-b);
            }
        }
        
        return fila.empty() ? 0 : fila.top();
    }
};