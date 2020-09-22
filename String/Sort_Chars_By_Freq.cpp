/* 451. Sort Characters By Frequency
Medium

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters. */

struct comp
{
    bool operator()(pair<char, int> a,pair<char, int> b)
    {
        return a.second > b.second;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mymap;
        for (char ch: s)
        {
            mymap[ch]++;
        }
        vector<pair<char, int>> A;
        // Copy key-value pair from Map 
        // to vector of pairs 
        for (auto& it : mymap) { 
            A.push_back(it); 
        } 
        std::sort(A.begin(), A.end(), comp());
        string res="";
        for (auto elem: A)
        {
            for (int i=0; i<elem.second; ++i)
                res += elem.first;
        }
        return res;
    }
};