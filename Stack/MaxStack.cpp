/* 716. Max Stack

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5 */

class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> max;
    MaxStack() {
        
    }
    
    void push(int x) {
        if (stk.empty())
        {
            max.push(x);
            stk.push(x);
        }
        else
        {
            max.top() > x? max.push(max.top()): max.push(x);
            stk.push(x);
        }
    }
    
    int pop() {
        int x = stk.top();
        stk.pop();
        max.pop();
        return x;
    }
    
    int top() {
        return stk.top();
    }
    
    int peekMax() {
        return max.top();
    }
    
    int popMax() {
        int max = peekMax();
        stack<int> buffer;
        while (top() != max) buffer.push(pop());
        pop();
        while (!buffer.empty()) 
        {
            push(buffer.top());
            buffer.pop();
        }
        return max;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
 
/* The problem with this solution is popMax() has a time complexity of O(n) where n is no of elements in the stack.
Can we make it faster, below approach uses, doublyLinkedList and map (O(n) find complexity)
and thus popMax is O(n) 
 */
class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> mp;
    
    MaxStack() { 
    }
    
    void push(int x) {
        v.insert(v.begin(),x);
        mp[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(it);
        return x;
    }
};