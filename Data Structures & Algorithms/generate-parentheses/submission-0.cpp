class Solution {
public:
    vector<string>res;
    bool isValid(string s){
        stack<char>st;
        for(char c: s){
            cout << c << endl;
            if(c == '(')
                st.push(c);
            else{
                if(!st.empty())
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
    void recurse(string s, int n){
        if(s.length() > n)
            return;
        if(s.length() == n and s.back() == ')' and isValid(s)){
            res.push_back(s);
            return;
        }
        s.push_back('(');
        recurse(s, n);
        s.pop_back();

        s.push_back(')');
        recurse(s, n);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        n *= 2;
        recurse("", n);
        return res;
    }
};