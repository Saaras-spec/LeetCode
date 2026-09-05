class MinStack {
    vector<int> s;
    vector<int> m;
    

public:
    MinStack() {
        
        
    }
    
    void push(int value) {
        s.push_back(value);
        if(m.empty()){
            m.push_back(value);
        }
        else{
            m.push_back(min(value,m.back()));
        }
        
    }
    
    void pop() {
        s.pop_back();
        m.pop_back();
        
    }
    
    int top() {
        return s.back();
        
    }
    
    int getMin() {
        return m.back();

        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */