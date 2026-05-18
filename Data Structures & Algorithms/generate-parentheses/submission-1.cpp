class Solution {
public:
    vector<string>res;
    stack<char>st;
    string s;
    int N;
    void recurse(){
        if(N == s.length() and st.empty()){
            res.push_back(s);
            return;
        }
        if(s.length() < N){
            st.push('(');
            s.push_back('(');
            recurse();
            st.pop();
            s.pop_back();
        }

        if(!st.empty()){
            st.pop();
            s.push_back(')');
            recurse();
            s.pop_back();
            st.push('(');
        }
    }
    vector<string> generateParenthesis(int n) {
        N = 2 * n;
        recurse();
        return res;
    }
};