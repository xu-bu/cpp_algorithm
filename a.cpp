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
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        for (int i = 0; i < n; ++i) {
            if(i<n-k)
        }
    }
};

int main() {
    string word = "ab";
    string prefix = "app";
    vector<int> nums = {6, 2, 2, 2, 6};
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2},
                                 {1, 3},
                                 {3, 4}};
    Solution solution = Solution();
    cout << solution.componentValue(nums, edges);

}


