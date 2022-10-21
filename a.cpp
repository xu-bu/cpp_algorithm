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
    // root:[children]
    unordered_map<int,vector<int>> dic;
    vector<int> subtreeSum;
    int value;
    int ans;
    //given the value of the sum of component, the return the max edge that can be deleted
    // assume note 0 is the root, then transform this graph into a tree. For each node i and its subtree j, if the sum of subtree j mod x equal 0, then this edge [i,j] should be deleted
    int sub(int root,vector<int>& nums, vector<vector<int>>& edges){
        int tmpAns=0;
        calculateSum(0,nums,edges);
        for(auto &each:dic[root]){
            if(subtreeSum[each]%value==0){
                tmpAns++;
            }
            tmpAns+=sub(each,nums,edges);
        }
        return tmpAns;
    }

    int calculateSum(int root,vector<int>& nums, vector<vector<int>>& edges){
        subtreeSum[root]+=nums[root];
        for (auto &each:dic[root]){
            subtreeSum[each]=calculateSum(each,nums,edges);
            subtreeSum[root]+= calculateSum(each,nums,edges);
        }
        return subtreeSum[root];
    }

    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        subtreeSum=vector<int> (nums.size());
        for (auto &each:edges){
            dic[each[0]].emplace_back(each[1]);
        }
        ans=0;
        int sum= accumulate(nums.begin(),nums.end(),0);
        for (int i = 2 ; i <= sum/2; ++i) {
            if(sum%i==0){
                value=i;
                ans=max(sub(0,nums,edges),ans);
            }
        }
        return ans;
    }
};

int main() {
    string word = "ab";
    string prefix = "app";
    vector<int> nums = {6,2,2,2,6};
    vector<vector<int>> edges={{0,1},{1,2},{1,3},{3,4}};
    Solution solution = Solution();
    cout<<solution.componentValue(nums,edges);

}


