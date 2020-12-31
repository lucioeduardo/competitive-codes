class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        
        int res=0;
        
        int i=0;
        
        while(i<n){
            if(st.empty() || heights[st.top()] <= heights[i])
                st.push(i++);
            else{
                int t = st.top();
                st.pop();
                
                int area = heights[t]*(st.empty() ? i:i-st.top()-1);
                res = max(res,area);
            }
        }
        
        while(!st.empty()){
            int t = st.top();
            st.pop();

            int area = heights[t]*(st.empty() ? i:i-st.top()-1);
            res = max(res,area);
        }
        
        return res;
    }
};