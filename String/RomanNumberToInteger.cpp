/* Roman to Integer
Easy

2383

3613

Add to List

Share
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3 */


class Solution {
public:
    int romanToInt(string s) {
        map<char, unsigned int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i=0;
        int count = 0;
        while (i <s.length()-1)
        {
            if (s[i] == 'I' and (s[i+1] == 'V' or s[i+1] == 'X'))
            {
                count = count + (m[s[i+1]] - m[s[i]]);
                cout <<count<<endl;
                i +=2;
            }
            else if (s[i] == 'X' and (s[i+1] == 'L' or s[i+1] == 'C'))
            {
                count = count + (m[s[i+1]] - m[s[i]]);
                cout <<count<<endl;
                i +=2;
            }
            else if (s[i] == 'C' and (s[i+1] == 'D' or s[i+1] == 'M'))
            {
                count = count + (m[s[i+1]] - m[s[i]]);
                cout <<count<<endl;
                i +=2;
            }
            else
            {
                count += m[s[i++]];
                cout <<count<<endl;
            } 
        }
        if (i<s.length())
        {
            count += m[s[i]];
            cout <<count<<endl;
        }
        return count;
        
    }
};