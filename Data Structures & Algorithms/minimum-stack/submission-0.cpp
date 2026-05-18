class MinStack {
public:
    vector<int>vals, mins;

    MinStack() {

    }
    
    void push(int val) {
        vals.push_back(val);
        mins.size() ? mins.push_back(min(mins.back(), val)) : mins.push_back(val);
    }
    
    void pop() {
        vals.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return vals.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
