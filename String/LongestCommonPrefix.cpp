/* Longest Common Prefix
Easy

2823

1930

Add to List

Share
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings. */


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if (strs.size()==0)
            return ret;
        for (int i=0; i< strs[0].length(); ++i)
        {
            for (int j = 1;j<strs.size(); ++j)
            {
                cout<<i <<" "<<j<<endl;
                if (i>= strs[j].length() or strs[0][i] != strs[j][i])
                    return ret;
            }
            ret += strs[0][i];
        }
        return ret;
    }
};