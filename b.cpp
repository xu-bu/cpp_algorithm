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
    //given the value of each component, return the max edges can be deleted
    int sub(int value,vector<int>& nums, vector<vector<int>>& edges){
        //for any note i, if itself's weight equal value, of course we should delete edge [i,j]. If its child j's subtree sum equal the multiple of value
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum= accumulate(nums.begin(),nums.end(),0);
        for (int i = sum/2; i >=2 ; --i) {
            if (sum%i==0){
                int value=sum/i;

            }
        }
        return 0;
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