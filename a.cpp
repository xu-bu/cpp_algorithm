#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int ans = nums[0];
        int n = nums.size();
        int minDP, maxDP;

        for (int i = 1; i < n; i++) {
            int temp = maxDP;
            maxDP = max(nums[i], max(nums[i] * maxDP, nums[i] * minDP));
            minDP = min(nums[i], max(nums[i] * temp, nums[i] * minDP));
        }
        ans = max(ans, maxDP);
        return ans;
    }
};

int main() {
    vector<int> nums = {-2, -3, 7};
    Solution s = Solution();
    cout << s.maxProduct(nums);
}