#include <bits/stdc++.h>

#include <utility>

using namespace std;

// 208
class Trie
{
private:
    // if search "a" and there's a "ab",return node 'a'
    Trie *searchPrefix(string prefix)
    {
        Trie *t = this;
        for (auto &ch : prefix)
        {
            ch -= 'a';
            if (t->children[ch] == nullptr)
            {
                return nullptr;
            }
            t = t->children[ch];
        }
        return t;
    }

public:
    vector<Trie *> children;
    bool isEnd;
    Trie() : children(26), isEnd(false)
    {
    }

    void insert(string word)
    {
        Trie *t = this;
        for (auto &ch : word)
        {
            ch -= 'a';
            if (t->children[ch] == nullptr)
            {
                t->children[ch] = new Trie();
            }
            t = t->children[ch];
        }
        t->isEnd = true;
    }

    bool search(string word)
    {
        Trie *t = searchPrefix(word);
        if (t == nullptr)
        {
            return false;
        }
        return t->isEnd;
    }

    bool startsWith(string prefix)
    {
        Trie *t = searchPrefix(prefix);
        return t != nullptr;
    }
};

int main()
{
    vector<int> nums = {2, 2, 3, -1};
    string prefix = "app";

    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words;
    words = {"oath", "pea", "eat", "rain"};
}
