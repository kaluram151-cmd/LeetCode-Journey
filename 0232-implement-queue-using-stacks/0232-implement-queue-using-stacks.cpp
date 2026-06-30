class MyQueue {
private: 
    stack<int> st;
public:
    MyQueue() {
    }
    
    void push(int x) {
        stack<int> s2;
        int p = st.size();
        for(int i = 0;i<p;i++)
        {
            s2.push(st.top());
            st.pop();
        }
        st.push(x);
        p = s2.size();
        for(int i = 0;i<p;i++)
        {
            st.push(s2.top());
            s2.pop();
        }
        return ;
    }
    
    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */