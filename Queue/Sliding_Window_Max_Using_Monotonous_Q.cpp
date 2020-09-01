/*239. Sliding Window Maximum
 Sliding window minimum/maximum = monotonic queue. 

This is essentially the same idea as others' deque solution, but this is much more standardized and modulized. If you ever need to use it in your real product, this code is definitely more preferable.

What does Monoqueue mean?:

It has three basic options:

push: push an element into the queue; O (1) (amortized)

pop: pop an element out of the queue; O(1) (pop = remove, it can't report this element)

max: report the max element in queue;O(1)

It takes only O(n) time to process a N-size sliding window minimum/maximum problem. Because each element pushed to monotonic queue at most once.

Note: different from a priority queue (which takes O(nlogk) to solve this problem), it doesn't pop the max element: It pops the first element (in original order) in queue.
 */
class Monoqueue {
    deque<int> myque; // every element in this queue is maintained to be monotonously decreasing.
public:
    void push(int n) {
        while(!myque.empty() && myque.back() < n) myque.pop_back();
        myque.push_back(n);
    }
    
    int front() {
        return myque.front();
    }
    
    void pop(int n) {
        if(n == myque.front())
            myque.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Monoqueue mq;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(i < k-1) mq.push(nums[i]);
            else {
                mq.push(nums[i]);
                res.push_back(mq.front());
                mq.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};

/* or
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) 
        {
            if (!dq.empty() && dq.front() == i-k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
}; */