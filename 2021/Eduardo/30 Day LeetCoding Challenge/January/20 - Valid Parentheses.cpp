class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        map<char,char> mp = {{'(',')'}, {'[',']'}, {'{','}'}};
        
        for(char c: s){
            if(c == '(' || c == '[' || c == '{')
                st.push(c);
            else{
                if(st.empty()) return false;
                 
                char t = st.top(); st.pop();
                if(mp[t] != c) return false;
            }
        }
        
        return st.empty();
    }
};