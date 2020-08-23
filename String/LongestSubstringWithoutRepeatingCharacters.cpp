/* Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring. */
			 
			 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int res = 0;
        int j=0;
        set<char> temp;
        for (int i=0;i<s.length();++i)
        {
            if (temp.find(s[i]) == temp.end())
            {
                temp.insert(s[i]);
                len++;
            }
            else
            {
                cout<<len<<endl;
                if (len > res)
                    res = len;
                while(s[j]!= s[i])
                {
                    len--;
                    temp.erase(s[j]);
                    j++;
                }
                j++;
            } 
        }
        if (len > res)
            res = len;
        return res;
    }
};