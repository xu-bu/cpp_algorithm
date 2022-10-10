

#include <bits/stdc++.h>

#include <utility>

using namespace std;

struct TreeNode {
    TreeNode *left, *right;
    int val;

    TreeNode() : left(nullptr), right(nullptr), val(0) {};

    TreeNode(int x) : left(nullptr), right(nullptr), val(x) {};
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int ans = 0;
        int n = isConnected.size();
        bool visit[n];
        for (int i = 0; i < n; ++i) {
            if (visit[i]) {
                continue;
            }
            visit[i] = true;
            unordered_set<int> queue{i};
            int index = 0;
            while (index < queue.size()) {
                for (int j = 0; j < isConnected[i].size(); ++j) {
                    int each = isConnected[i][j];
                    if (each == 1) {
                        queue.emplace(j);
                    }
                }
                index++;
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    string word = "ab";
    string prefix = "app";

    Solution solution = Solution();
    solution.countSmaller(nums);
}


