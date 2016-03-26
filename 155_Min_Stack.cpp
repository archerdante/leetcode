#include <iostream>
#include <vector>
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) -- Push element x onto stack.
//pop() -- Removes the element on top of the stack.
//top() -- Get the top element.
//getMin() -- Retrieve the minimum element in the stack.
class MinStack {
public:
    void push(int x) {
        s_data.push_back(x);
        if(s_min.size() == 0 || s_min.back() > x)
        {
            s_min.push_back(x);
        }
        else
        {
            s_min.push_back(s_min.back());
        }
    }

    void pop() {
        assert(s_data.size() > 0 && s_min.size() > 0);
        s_data.pop_back();
        s_min.pop_back();
    }

    int top() {
        assert(s_data.size() > 0);
        return s_data.back();
    }

    int getMin() {
        assert(s_min.size() > 0);
        return s_min.back();
    }
private:
    vector<int> s_min;
    vector<int> s_data;
};
