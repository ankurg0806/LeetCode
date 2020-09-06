/* 211. Design Add and Search Words Data Structure
Medium

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search. */

class TrieNode
{
private:
    vector<TrieNode*> links;
    bool isEnding;
public:
    TrieNode(): links(26, nullptr), isEnding(false){}
    bool containsKey(char ch)
    {
        return links[ch-'a'] != nullptr;
    }
    TrieNode* get(char ch)
    {
        return links[ch-'a'];
    }
    vector<TrieNode*> getChildren()
    {
        vector<TrieNode*> children;
        for (char ch='a';ch<='z';++ch)
        {
            if (containsKey(ch))
            {
                children.push_back(get(ch));
            }
        }
        return children;
    }
    void put(char ch, TrieNode* node)
    {
        links[ch-'a'] = node;
    }
    void setEnd()
    {
        isEnding = true;
    }
    bool isEnd()
    {
        return isEnding;
    }
};
class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode){}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch: word)
        {
            if (not node->containsKey(ch))
            {
                node->put(ch, new TrieNode);
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchInNode(string word, TrieNode* node) {
        for (int i=0;i<word.size();++i)
        {
            if (word[i] == '.') 
            {
                vector<TrieNode*> children = node->getChildren();
                for (TrieNode* child: children)
                {
                    if (searchInNode(word.substr(i+1), child))
                    {
                        return true;
                    }
                }
                return false;
            }
            else if (!node->containsKey(word[i]))
            {
                return false;
            }
            else
                node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool search(string word)
    {
        return searchInNode(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */