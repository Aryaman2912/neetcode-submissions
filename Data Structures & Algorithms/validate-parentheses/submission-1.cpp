class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                st.push(s[i]);
            } else {
                if(st.empty())
                    return false;
                if(s[i] == ')' and st.top() == '(')
                    st.pop();
                else if(s[i] == '}' and st.top() == '{')
                    st.pop();
                else if(s[i] == ']' and st.top() == '[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
