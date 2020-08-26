/* Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9 */

class Solution {
public:
    bool isValidTime(vector<int>& A)
    {
        int hr = A[0]*10+A[1];
        int min = A[2]*10+A[3];
        if (hr<24 and min <60)
            return true;
        return false;
    }
string util(vector<int>& A)
{ 
    string res = "";
    int num=INT_MIN; 
    sort(A.begin(), A.end()); 
  
    // Keep printing next permutation while there 
    // is next permutation 
    do { 
        int temp = 0;
        for (auto d: A)
        {
            temp = temp*10 + d;
            if (temp>num and isValidTime(A))
            {
                num = temp;
            }
        }
    } while (next_permutation(A.begin(), A.end()));
    if (num == 0)
        return "00:00";
    if (num !=INT_MIN)
    {
        int count=0;
        while(num!=0)
        {
            count++;
            int d = num%10;
            num = num/10;
            res = std::to_string(d) + res;
            if (count ==2)
            {
                res = ":" + res;
            }
        }
    }
    if (res.size()<5 and res.size()>0)
    {
        res = "0" + res;
    }
    return res;
}
    string largestTimeFromDigits(vector<int>& A) {
        if (A.empty())
            return "";
       return util(A);
    }
};