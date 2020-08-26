/* Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
] */

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ans, vs;
        string str;

        int len = 0;
        for (int i = 0; i < words.size(); ++i) 
        {
            if ((len + words[i].size() + vs.size()) <=maxWidth)
            {
                vs.push_back(words[i]);
                len += words[i].size();
            }
            else
            {
                if (vs.size()==1)
                {
                    str = vs[0];
                    str.append(maxWidth-len, ' ');
                    ans.push_back(str);
                    str = "";
                }
                else if (vs.size()>1)
                {
                    int min_spaces = (maxWidth - len) / (vs.size()-1);
                    int words_with_extra_spaces = (maxWidth - len) % (vs.size()-1);
                    str = vs[0];
                    for (int j=1;j<vs.size();++j)
                    {
                        if (j <= words_with_extra_spaces)
                        {
                            str.append(min_spaces+1,' ');
                        }
                        else
                        {
                            str.append(min_spaces, ' ');
                        }
                        str += vs[j];
                    }
                    ans.push_back(str);
                }
                vs.clear();
                vs.push_back(words[i]);
                len = words[i].size();
            }
        }
        str = vs[0];
        for (int j=1;j<vs.size();++j)
        {
            str += ' ' + vs[j];
        }
        str.append(maxWidth - str.size(), ' ');
        ans.push_back(str);
        return ans;
    }
};