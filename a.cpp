

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
    vector<int> merge(vector<int> &v1,vector<int> &v2,vector<int> &nums){
        vector<int> ret;
        int i=0;
        while(i<v1.size() and i<v2.size()){
            if(nums[v1[i]]<nums[v2[i]]){
                ret.emplace_back(v1[i]);
            }else{
                ret.emplace_back(v2[i]);
            }
            i++;
        }
        while(i<v1.size()){
            ret.emplace_back(v1[i]);
            i++;
        }
        while(i<v2.size()){
            ret.emplace_back(v2[i]);
            i++;
        }
        return ret;
    }

    vector<int> mergeSort(vector<int> &indexs,vector<int> &nums){
        if(indexs.size()<=1){
            return indexs;
        }
        vector<int> l;
        l.assign(indexs.begin(),indexs.begin()+indexs.size()/2);
        vector<int> r;
        r.assign(indexs.begin()+indexs.size()/2,indexs.end());
        merge(l,r,nums);
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> indexs;
        for (int i = 0; i < nums.size(); ++i) {
            indexs.emplace_back(i);
        }
        vector<int> ans;
        ans=mergeSort(indexs,nums);
        return ans;
    }
};

int main() {
    string word = "ab";
    string prefix = "app";
    vector<int> nums={8,1,2,2,3};
    Solution solution = Solution();
    solution.smallerNumbersThanCurrent(nums);
}


