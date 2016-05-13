#include <stack>
using namespace std;
//Implement the following operations of a queue using stacks.
//push(x) -- Push element x to the back of queue.
//pop() -- Removes the element from in front of queue.
//peek() -- Get the front element.
//empty() -- Return whether the queue is empty.
//Notes:
//You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
//Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
//You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
class Queue {
public:
    
    void push(int x) {
        s_1.push(x);
    }

    
    void pop(void) {
        if(!s_2.empty())
        {
            s_2.pop();
        }
        else
        {
            while(!s_1.empty())
            {
                s_2.push(s_1.top());
                s_1.pop();
            }
            s_2.pop();
        }
    }

    
    int peek(void) {
        if(!s_2.empty())
        {
            return s_2.top();
        }
        else
        {
            while(!s_1.empty())
            {
                s_2.push(s_1.top());
                s_1.pop();
            }
            return s_2.top();
        }
    }

    
    bool empty(void) {
        return s_1.empty() && s_2.empty();
    }
private:
    stack<int> s_1;
    stack<int> s_2;
};
