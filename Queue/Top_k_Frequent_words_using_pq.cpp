692. Top K Frequent Words
Medium

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

struct Comp
{
    bool operator() (const pair<string, int>& lhs, const pair<string, int>&rhs)
    {
        if ( lhs.second != rhs.second ) {
        // put on top the pair with less frequency
        return lhs.second > rhs.second;
      }
      // put on top the pair with greater lexicography
      return lhs.first < rhs.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> freq_map;
        for (auto& word: words)
            freq_map[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, Comp> q;
        for (auto& item: freq_map)
        {
            cout<<item.first<<endl;
            q.push({item.first, item.second});
            cout<<q.top().first;
            if (q.size()>k)
                q.pop();
        }
        vector<string> res(k);
        k--;
        while(!q.empty())
        {
            res[k--] = q.top().first;
            q.pop();
        }
        return res;
    }
};