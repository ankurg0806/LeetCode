/* Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

Time complexity: We are expanding the string left and right at each index to a maximum of string length, thus it is proportional of n times n i.e. O(n*n) */


class Solution {
public:
    // left = right, when we are trying to explore palindrome with odd size
    // right = left+1 when trying for even size palindrome
    int expand(const string& s, int left, int right)
    {
        while (left >=0 and right<s.size() and s[left] == s[right])
        {
            left--;
            right++;
        }
        return right -left -1;
    }
    string longestPalindrome(string s) {
        if (s.empty())
            return s;
        int start = 0, end = 0;
        for (int i=0;i<s.size();++i)
        {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i+1);
            int len = std::max(len1, len2);
            if (len > end - start)
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);  
    }
};