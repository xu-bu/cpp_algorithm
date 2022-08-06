#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    ListNode *next;
    int val;

    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next{nullptr} {};
};

class Solution {
public:
    int calPoints(vector<string>& ops) {

    }
};

int main() {
    vector<int> nums = {2, 2, 3, -1};
    vector<int> pop = {1, 2, 3, 4, 5};
    string s = "ab";
    string p = ".*";
    Solution solution = Solution();
    cout << solution.validateStackSequences(nums, pop);
}
