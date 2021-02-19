class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        
        for(int i=0; i<s.length(); i++){
            char c = s[i];
            
            if(c == '(')
                st.push(i);
            else if(c == ')'){
                if(!st.empty()) st.pop();
                else{
                    s[i]='.';
                }
            }
        }
                
        while(!st.empty()){
            int t = st.top(); st.pop();            
            s[t]='.';
        }
        
        string res = "";
        
        for(char c: s){
            if(c != '.')
                res += c;
        }
        
        return res;
    }
};