/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR" */

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> st(numRows);
        if (numRows == 1)
            return s;
        int i=0;
        bool down=true;
        for (char ch: s)
        {
            if (down)
            {
                st[i] = st[i] + ch;
                i++;
                if (i== numRows)
                {
                    i -=2;
                    down = false;
                }
            }
            else
            {
                st[i] += ch;
                i--;
                if (i==-1)
                {
                    i += 2;
                    down = true;
                }
            }
        }
        string res = "";
        for (string temp: st)
        {
            res += temp;
        }
        return res;
    }
};