/* Employee Free Time

We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

(Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined).  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

 

Example 1:

Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
Output: [[3,4]]
Explanation: There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:

Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
Output: [[5,6],[7,9]]
 

Constraints:

1 <= schedule.length , schedule[i].length <= 50
0 <= schedule[i].start < schedule[i].end <= 10^8 */

/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> sortedIntervals;
        vector<Interval> res;
        if(schedule.size()==1 and schedule[0].size()<=1)
            return res;
        for (auto& vec_interval: schedule)
        {
            for(auto& interval : vec_interval)
            {
            int key = interval.start;
            int val = interval.end;
            if (sortedIntervals.find(key) == sortedIntervals.end())
            {
                sortedIntervals[key] = val;
            }
            else
            {
                if (val>sortedIntervals[key])
                    sortedIntervals[key] = val;
            }
        }
        }
        auto iter = sortedIntervals.begin();
        auto iter1 = sortedIntervals.begin(); ++iter1;
        while (iter1!=sortedIntervals.end())
        {
            if (iter1->first < iter->second)
            {
                if (iter1->second>iter->second)
                    sortedIntervals[iter->first] = iter1->second;
                iter1 = sortedIntervals.erase(iter1);
            }
            else
            {
                ++iter;
                ++iter1;
            }
        }
        if(sortedIntervals.size()<=1)
            return res;
        iter = sortedIntervals.begin();
        iter1 = sortedIntervals.begin();++iter1;
        while(iter1!=sortedIntervals.end())
        {
            Interval ob;
            ob.start = iter->second;
            ob.end = iter1->first;
            if(ob.start<ob.end)
                res.push_back(ob);
            ++iter;
            ++iter1;
        }
        return res;
    }
};