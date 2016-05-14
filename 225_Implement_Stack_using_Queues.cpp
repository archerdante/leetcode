#include <deque>
using namespace std;
//Implement the following operations of a stack using queues.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//empty() -- Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
class Stack {
public:
    void push(int x) {
        if(q_1.empty()) q_2.push_back(x);
        else q_1.push_back(x);
        n = x;
    }

    void pop() {
        if(q_1.empty())
        {
            while(q_2.size() > 1)
            {
                q_1.push_back(q_2.front());
                if(q_2.size() == 2) n = q_2.front();
                q_2.pop_front();
            }
            q_2.pop_front();
        }
        else
        {
            while(q_1.size() > 1)
            {
                q_2.push_back(q_1.front());
                if(q_1.size() == 2) n = q_1.front();
                q_1.pop_front();
            }
            q_1.pop_front();
        }
    }

    int top() {
        return n;
    }
    
    bool empty() {
        return q_1.empty() && q_2.empty();
    }
private:
    deque<int> q_1;
    deque<int> q_2;
    int n;
};
