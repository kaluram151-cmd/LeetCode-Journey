class MinStack {
private:
    stack<long long> st;
    long long min;
    public:
    MinStack() {

    }
    
    void push(int value) {
        if(st.empty())
        {
            st.push(value);
            min = value;
            return ;
        }
        else
        {
            if(value>=min)
            {
                st.push(value);
            }
            else
            {
                long long val = value;
                long long newvalue = 2LL*val-min;
                st.push(newvalue);
                min = value;
            }
        }
        
        return ;
    }
    
    void pop() {
        long long n = st.top();
        st.pop();
        if(n<min)
        {
            min = 2LL*min-n;
        }
    }
    
    int top() {
        long long n = st.top();
        if(n<min)
        {
            return (int)min;
        }
        return (int)n;

    }
    
    int getMin() {
        return (int)min;
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