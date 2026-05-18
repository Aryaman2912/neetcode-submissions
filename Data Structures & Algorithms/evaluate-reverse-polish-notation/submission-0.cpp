class Solution {
public:
    stack<int>st;
    int to_int(string sval){
        int val = 0;
        int i = 0;
        if(sval[0] == '-')
            i++;
        while(i < sval.length())
            val = val * 10 + (sval[i++]-'0');
        if(sval[0] == '-')
            val *= -1;
        return val;
    }
    void eval(string op){
        int v1 = st.top();st.pop();
        int v2 = st.top(); st.pop();
        if(op == "+")
            st.push(v1 + v2);
        else if(op == "-")
            st.push(v2 - v1);
        else if(op == "*")
            st.push(v1 * v2);
        else if(op == "/")
            st.push(v2 / v1);
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/")
                eval(tokens[i]);
            else
                st.push(to_int(tokens[i]));
        }
        return st.top();
    }
};
