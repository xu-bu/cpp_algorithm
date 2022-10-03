#include <bits/stdc++.h>

#include <utility>

using namespace std;

//208
class Trie {
private:


    //if search "a" and there's a "ab",return node 'a'
    Trie *searchPrefix(string prefix) {
        Trie *t = this;
        for (auto &ch: prefix) {
            ch -= 'a';
            if (t->children[ch] == nullptr) {
                return nullptr;
            }
            t = t->children[ch];
        }
        return t;
    }

public:
    vector<Trie *> children;
    bool isEnd;
    Trie() : children(26), isEnd(false) {

    }

    void insert(string word) {
        Trie *t = this;
        for (auto &ch: word) {
            ch -= 'a';
            if (t->children[ch] == nullptr) {
                t->children[ch] = new Trie();
            }
            t = t->children[ch];
        }
        t->isEnd = true;
    }

    bool search(string word) {
        Trie *t = searchPrefix(word);
        if (t == nullptr) {
            return false;
        }
        return t->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *t = searchPrefix(prefix);
        return t != nullptr;
    }
};

//212
class Solution {
private:
    Trie* head;
    int rows,cols;
public:
    void init(vector<vector<char>> &board) {
        head=new Trie();
        rows=board.size();
        cols=board[0].size();
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                char ch=board[i][j];
                if(!head->children[ch-'a']){
                    head->children[ch-'a']=new Trie();
                }
                Trie *child=head->children[ch-'a'];
                if(i!=0){
                    char upper=board[i-1][j];
                    if(!child->children[upper-'a']){
                        child->children[upper-'a']=new Trie();
                    }
                }
                if(j!=0){
                    char left=board[i][j-1];
                    if(!child->children[left-'a']){
                        child->children[left-'a']=new Trie();
                    }
                }
                if(i!=rows-1){
                    char down=board[i+1][j];
                    if(!child->children[down-'a']){
                        child->children[down-'a']=new Trie();
                    }
                }
                if(j!=cols-1){
                    char right=board[i][j+1];
                    if(!child->children[right-'a']){
                        child->children[right-'a']=new Trie();
                    }
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        init(board);
        vector<string> ans;
        for(auto &each:words){
            if(head->startsWith(each)){
                ans.emplace_back(each);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 2, 3, -1};
    string prefix = "app";

    vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words;
    words={"oath","pea","eat","rain"};
    Solution solution = Solution();
    vector<string> tmp=solution.findWords(board,words);
    for(auto &each:tmp){
        cout<<each<<endl;
    }
}


