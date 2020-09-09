/* First Unique Character in a String

Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters.
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> arr(256,0); 
  
        for (int i = 0; s[i]; i++) { 
            arr[s[i]]++; 
        } 

        int res = INT_MAX; 
        for (int i = 0; s[i]; i++) 
        {
            if (arr[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};