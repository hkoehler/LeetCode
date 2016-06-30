// https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        memset(nodes, 0, sizeof(nodes));
    }
    TrieNode *nodes[26];
    bool last = false;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *curr = root;
        
        for (auto c : word) {
            int i = c - 'a';
            if (curr->nodes[i] == nullptr)
                curr->nodes[i] = new TrieNode();
            curr = curr->nodes[i];
        }
        curr->last = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *curr = root;
        
        for (auto c : word) {
            int i = c - 'a';
            if (curr->nodes[i] == nullptr)
                return false;
            curr = curr->nodes[i];
        }
        return curr->last;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        
        for (auto c : prefix) {
            int i = c - 'a';
            if (curr->nodes[i] == nullptr)
                return false;
            curr = curr->nodes[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
