/* String Compression

Solution
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 
Example 1:

Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
 

Example 2:

Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
 

Example 3:

Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array. */

class Solution {
private:
    int countDigit(int num)
    {
        int count=0;
        while (num!=0)
        {
            count++;
            num=num/10;
        }
        return count;
    }
public:
    int compress(vector<char>& chars) {
        vector<int> hashtable(26, 0);
        vector<char> result;
        int res=0;
        for (int i=0;i<chars.size();i++)
        {
            result.push_back(chars[i]);
            res++;
            int j=i+1;
            int count = 1;
            while (j<chars.size() and chars[j] == chars[i])
            {
                count++;
                j++;
            }
            if (count>1)
            {
                vector<char> temp;
                while (count>0)
                {
                    res++;
                    temp.push_back('0' + (count%10));
                    count=count/10;
                }
                std::reverse(temp.begin(), temp.end());
                for (char ch: temp)
                {
                    result.push_back(ch);
                }
            }
            i = j-1;
        }
        chars = result;
        return res;
    }
};