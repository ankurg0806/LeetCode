/* 346. Moving Average from Data Stream
Easy

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3 */

class MovingAverage {
private:
    int w_size;
    list<int> win;
    int count;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : w_size(size), count(0), sum(0.0){}
    
    double next(int val) {
        if (count<w_size)
        {
            ++count;
            win.push_back(val);
            sum +=val;
            return sum/count;
        }
        else
        {
            sum = sum+val;
            win.push_back(val);
            sum = sum - win.front();
            win.pop_front();
        }
        return sum/w_size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */