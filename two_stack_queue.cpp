//
// Created by peilin.wu on 2023/4/10.
//

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        s_in.push(x);
    }

    int pop() {
        int val;
        // 判断s_out是否为空，如果s_out不为空，直接返回栈顶并使用pop()删除栈顶元素；
        if (s_out.empty()){
            in_2_out();
        }
        val = s_out.top();
        s_out.pop();
        return val;
    }

    int peek() {
        // 只返回栈顶元素，不删除；
        if(s_out.empty()){
            in_2_out();
        }
        return s_out.top();
    }

    bool empty() {
        // s_in 和 s_out都为空才返回true；
        return (s_in.empty() && s_out.empty());
    }
public:
    stack<int> s_in;
    stack<int> s_out;
private:
    void in_2_out(){
        // 出栈s_in所有元素，压栈给s_out;
        while(!s_in.empty()){
            s_out.push(s_in.top());
            s_in.pop();
        }
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
