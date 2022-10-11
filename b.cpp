#include <bits/stdc++.h>

using namespace std;

class dicTree {
public:
    bool end = false;
    char ch;
    vector<dicTree *> children;

    dicTree() : children(vector<dicTree *>(26)) {}

    dicTree(char ch) : children(vector<dicTree *>(26)), ch(ch) {}

    void add(dicTree *node) {
        int index = node->ch - 'a';
        if (children[index] == nullptr) {
            children[index] = node;
        }
    }

    //original word is 'apple', this node is 'a' and now query 'pple'
    bool query(string word) {
        if (word.size() == 0) {
            end = true;
            return true;
        }
        auto child = children[word.at(0) - 'a'];
        if (child != nullptr) {
            return child->query(word.substr(1, word.size() - 1));
        }
        return false;
    }
};

class Solution {
public:
    int rows, cols;

    void dfs(dicTree *trie, int x, int y, vector<vector<char>> &board) {
        trie->children[board[x][y] - 'a'] = new dicTree(board[x][y]);
        if (x - 1 >= 0) {
            dfs(&dicTree(board[x - 1][y]))
        }
        if (y - 1 >= 0) {
            char ch = board[x][y - 1];
            node->add(nodes[ch - 'a']);
        }
        if (x + 1 < board.size()) {
            char ch = board[x + 1][y];
            node->add(nodes[ch - 'a']);
        }
        if (y + 1 < board[0].size()) {
            char ch = board[x][y + 1];
            node->add(nodes[ch - 'a']);
        }

    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        rows = board.size();
        cols = board[0].size();
        vector<dicTree *> nodes(26);
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < cols; ++y) {
                nodes[board[x][y] - 'a'] = new dicTree(board[x][y]);
            }
        }
        for (int x = 0; x < rows; ++x) {
            for (int y = 0; y < cols; ++y) {
                dicTree *node = nodes[board[x][y] - 'a'];
                if (x - 1 >= 0) {
                    char ch = board[x - 1][y];
                    node->add(nodes[ch - 'a']);
                }
                if (y - 1 >= 0) {
                    char ch = board[x][y - 1];
                    node->add(nodes[ch - 'a']);
                }
                if (x + 1 < board.size()) {
                    char ch = board[x + 1][y];
                    node->add(nodes[ch - 'a']);
                }
                if (y + 1 < board[0].size()) {
                    char ch = board[x][y + 1];
                    node->add(nodes[ch - 'a']);
                }
            }
        }
        vector<string> ans;
        for (auto &word: words) {
            for (auto &node: nodes) {
                if (node->ch == word.at(0) and node->query(word.substr(1, word.size() - 1))) {
                    ans.emplace_back(word);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 0, 0, 2, 4, 4, 1};
    vector<int> pop = {1, 2, 3, 4, 5};
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    bool a = false;
    a = a & true;
    cout << a;
//    Solution solution = Solution();
//    cout << solution.ladderLength(beginWord,endWord,wordList);
}