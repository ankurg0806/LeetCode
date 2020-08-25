/* Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping. */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> interval_map;
        if (intervals.size() <= 1)
            return intervals;
        for (int i=0;i<intervals.size();++i)
        {
            if (interval_map.find(intervals[i][0]) == interval_map.end())
            {
                interval_map[intervals[i][0]] = intervals[i][1];
            }
            else
            {
                interval_map[intervals[i][0]] = std::max(interval_map[intervals[i][0]], intervals[i][1]);
            }
        }
        auto iter = interval_map.begin();
        auto iter1 = interval_map.begin();
        ++iter1;
        while (iter1!= interval_map.end())
        {
            if (iter1->first <= iter->second)
            {
                iter->second = std::max(iter1->second, iter->second);
                iter1 = interval_map.erase(iter1);
            }
            else
            {
                iter = iter1;
                ++iter1;
            }
        }
        vector<vector<int>> res;
        for (auto iter1 = interval_map.begin(); iter1!= interval_map.end(); ++iter1)
        {
            vector<int> temp;
            temp.push_back(iter1->first);
            temp.push_back(iter1->second);
            res.push_back(temp);
        }
        return res;
    }
};