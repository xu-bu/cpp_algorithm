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
    //given the value of the sum of component, the return the max edge that can be deleted
    int sub(int value,vector<int>& nums, vector<vector<int>>& edges){

    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {

    }
};

int main() {
    string word = "ab";
    string prefix = "app";
    vector<int> nums = {8,1,2,2,3};
    Solution solution = Solution();
    nums=solution.smallerNumbersThanCurrent(nums);
    for (auto each: nums) {
        cout << each << endl;
    }
}


