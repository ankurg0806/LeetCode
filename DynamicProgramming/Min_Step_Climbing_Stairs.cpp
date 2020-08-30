/* On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach past the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3]. */

// Memory efficient Bottom up DP approach
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()];
        if (cost.size()==1)
            return cost[0];
        if (cost.size()==0)
            return 0;
        int a = cost[0];
        int b = cost[1];
        int i=2;
        for (i=2;i<cost.size();++i)
        {
            int curr = min(a, b) + cost[i];
            a = b;
            b = curr;
        }
        return min(a,b);
    }
};