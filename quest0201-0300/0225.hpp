#ifndef __0225_H
#define __0225_H

/*****************************************************
Description:
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack
should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:
* void push(int x) Pushes element x to the top of the stack.
* int pop() Removes the element on the top of the stack and returns it.
* int top() Returns the element on the top of the stack.
* boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
You must use only standard operations of a queue, which means that only push to back,
peek/pop from front, size and is empty operations are valid. Depending on your language,
the queue may not be supported natively. You may simulate a queue using a list or deque
(double-ended queue) as long as you use only a queue's standard operations.

Example 1:
Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False

Constraints:
1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
*****************************************************/

#include "../includes.hpp"

class MyStack {
    std::queue<int> tik;
    std::queue<int> tok;
    bool use_tik;

public:
    MyStack() { use_tik = true; }

    void push(int x) {
        if (use_tik) {
            tik.push(x);
        } else {
            tok.push(x);
        }
    }

    int pop() {
        auto impl = [](std::queue<int> &src, std::queue<int> &dst) -> int {
            // assert(!src.empty() && dst.empty());
            size_t sz = src.size();
            for (size_t i = 0; i < sz - 1; ++i) {
                dst.push(src.front());
                src.pop();
            }
            int ret = src.front();
            src.pop();
            return ret;
        };
        if (use_tik) {
            use_tik = false;
            return impl(tik, tok);
        } else {
            use_tik = true;
            return impl(tok, tik);
        }
    }

    int top() {
        int ret = pop();
        push(ret);
        return ret;
    }

    bool empty() {
        if (use_tik) {
            return tik.empty();
        } else {
            return tok.empty();
        }
    }
};

#endif
