// https://leetcode.com/problems/word-search-ii/

class Node {
public:
    Node *nodes[26];
    bool last = false;
    string word;
    char val;

    Node(char c) : val(c) {
        memset(nodes, 0, sizeof(nodes));
    }

    void insert(string s) {
        Node *curr = this;
        
        for (auto c : s) {
            int i = c - 'a';
            if (curr->nodes[i] == nullptr)
                curr->nodes[i] = new Node(c);
            curr = curr->nodes[i];
        }
        curr->last = true;
        curr->word = s;
    }
};

class Solution {
    vector<string> foundWords;
public:
    void search(vector<vector<char>>& board, Node *node, int x, int y) {
        //printf("x=%x y=%x val=%c\n", x, y, node->val);
        // consumed a whole word
        if (node->last) {
            node->last = false;
            foundWords.push_back(node->word);
        }
        // check boundaries
        if (x < 0 || x >= board.size())
            return;
        if (y < 0 || y >= board[x].size())
            return;
        char t = board[x][y];
        if (t == '\0')
            return;
        int i = t - 'a';
        if (node->nodes[i]) {
            node = node->nodes[i];
            // don't visit a cell more than once
            board[x][y] = '\0';
            search(board, node, x+1, y);
            search(board, node, x-1, y);
            search(board, node, x, y+1);
            search(board, node, x, y-1);
            board[x][y] = t;
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node root('$');
        
        for (auto s : words)
            root.insert(s);
        for (int x = 0; x < board.size(); x++)
            for (int y = 0; y < board[x].size(); y++)
                search(board, &root, x, y);
        sort(foundWords.begin(), foundWords.end());
        return foundWords;
    }
};
