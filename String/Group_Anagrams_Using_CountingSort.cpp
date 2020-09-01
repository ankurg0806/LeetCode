/* 49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]] */


// Using counting sort will result in O(k) complexity of sort where k is length of string
// Overall complexity will be O(nk) where n is no of strings and k is max string length
class Solution {
public:
    string sortLowercase(string s) {
        int charExist[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            charExist[s[i] - 'a']++;
        }
        string res;
        int j = 0;
        while (j < 26) {
            if (charExist[j] == 0) {
                j++;
            }
            else {
                res.push_back(j + 'a');
                charExist[j]--;
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> temp;
        vector<vector<string>> res;
        for (auto& str: strs)
        {
            auto sortedS = sortLowercase(str);
            if (temp.find(sortedS) == temp.end())
            {
                vector<string> st{str};
                temp.emplace(sortedS, st);
            }
            else
            {
                temp[sortedS].push_back(str);
            }
        }
        for (auto elem: temp)
        {
            res.push_back(elem.second);
        }
        return res;
    }
};