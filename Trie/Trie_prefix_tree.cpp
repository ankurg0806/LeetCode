/* 208. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings. */

class TrieNode
{
    private:
    vector<TrieNode*> links;
    bool isEndingHere;
    public:
    TrieNode(): links(26, nullptr), isEndingHere(false)
    {}
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    TrieNode* get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, TrieNode* node)
    {
        links[ch-'a'] = node;
    }
    void setEnd()
    {
        isEndingHere = true;
    }
    bool isEnd()
    {
        return isEndingHere;
    }  
};

class Trie {
private:
    TrieNode* root;
    TrieNode* searchPrefix(string word)
    {
        TrieNode* node = root;
        for (char ch: word)
        {
            if (node->containsKey(ch))
            {
                node = node->get(ch); 
            }
            else
            {
                return nullptr;
            }
        }
        return node;
    }
public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode){}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char ch: word)
        {
            if (not node->containsKey(ch))
            {
                cout<<"here";
                node->put(ch, new TrieNode);
                cout<<"here";
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node!= nullptr and node->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */