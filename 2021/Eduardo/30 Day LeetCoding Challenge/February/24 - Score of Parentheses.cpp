class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        
        
        for(int i=0; i<S.length(); i++){
            char c = S[i];
            
            if(c == '(')
                st.push(-1);
            else{
                
                
                if(st.top() == -1){
                    st.pop();
                    st.push(1);
                }else{
                    int x = 0;    
                    while(st.top() != -1){
                        x += st.top(); st.pop();
                    }
                    x*=2;
                    
                    st.pop();
                    st.push(x);
                }
                
            }
        }
        
        int res=0;
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};