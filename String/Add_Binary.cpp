/* Add Binary

Solution
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero. */

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        int i=a.size()-1;
        int j=b.size()-1;
        int carry = 0;
        string output="";
        while (i>=0 and j>=0)
        {
            int d1 = a[i--] - '0';
            int d2 = b[j--] - '0';
            int sum = carry + d1 + d2;
            if (sum>1)
                carry = 1;
            else
                carry = 0;
            sum = sum%2;
            output = std::to_string(sum) + output;    
        }
        while (i>=0)
        {
            int d1 = a[i--] - '0';
            int sum = carry + d1;
            if (sum>1)
                carry = 1;
            else
                carry = 0;
            sum = sum%2;
            output = std::to_string(sum) + output;  
        }
        while (j>=0)
        {
            int d2 = b[j--] - '0';
            int sum = carry + d2;
            if (sum>1)
                carry = 1;
            else
                carry = 0;
            sum = sum%2;
            output = std::to_string(sum) + output;
        }
        if (carry == 1)
        {
            output = std::to_string(carry) + output;
        }
        return output;
    }
};