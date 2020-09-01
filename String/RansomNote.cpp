/* 383. Ransom Note

Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true */

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hashtable(26,0);
        for (char ch: magazine)
        {
            hashtable[ch-'a']++;
        }
        for (char ch: ransomNote)
        {
            if (hashtable[ch-'a']>0)
            {
                hashtable[ch-'a']--;
            }
            else
                return false;
        }
        return true;
    }
};