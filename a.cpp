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
    vector<int> merge(vector<int> &v1, vector<int> &v2, vector<int> &nums) {
        vector<int> ret;
        int p = 0, q = 0;
        while (p < v1.size() and q < v2.size()) {
            if (nums[v1[p]] < nums[v2[q]]) {
                ret.emplace_back(v1[p]);
                p++;
            } else {
                ret.emplace_back(v2[q]);
                q++;
            }
        }
        while (p < v1.size()) {
            ret.emplace_back(v1[p]);
            p++;
        }
        while (q < v2.size()) {
            ret.emplace_back(v2[q]);
            q++;
        }
        return ret;
    }

    vector<int> mergeSort(vector<int> &indexs, vector<int> &nums, int start, int end) {
        if (indexs.size() <= 1) {
            return indexs;
        }
        vector<int> l;
        int mid = start + ((end - start) >> 1);
        for (int i = 0; i < mid; ++i) {
            l.emplace_back(indexs[i]);
        }
        l=mergeSort(l, nums, start, mid);
        vector<int> r;
        for (int i = mid; i < end; ++i) {
            r.emplace_back(indexs[i]);
        }
        r=mergeSort(r, nums, mid, end);;
        return merge(l, r, nums);
    }

    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> indexs;
        for (int i = 0; i < nums.size(); ++i) {
            indexs.emplace_back(i);
        }
        vector<int> ans(nums.size());
        indexs = mergeSort(indexs, nums, 0, nums.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[indexs[i]]=i;
        }
        return ans;
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


