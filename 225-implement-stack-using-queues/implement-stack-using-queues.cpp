class MyStack {
private:
    queue<int> q1, q2;
public:
    MyStack() {}
    
    void push(int x) {
        if(q1.empty()){
            q2.push(x);
        } else {
            q1.push(x);
        }
    }
    
    int pop() {
        int x;
        if(q1.empty()){
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            x = q2.front();
            q2.pop();
        } else {
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            x = q1.front();
            q1.pop();
        }
        return x;
    }
    
    int top() {
        int x;
        if(q1.empty()){
            while(q2.size() > 1){
                q1.push(q2.front());
                q2.pop();
            }
            x = q2.front();
            q1.push(x);
            q2.pop();
        } else {
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            x = q1.front();
            q2.push(x);
            q1.pop();
        }
        return x;
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */