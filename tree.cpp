#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {};
};

class Codec {
public:
    int countHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(countHeight(root->left), countHeight(root->right));
    }

    string serialize(TreeNode *root) {
        if (!root) {
            return "";
        }
        vector<TreeNode *> queue{root};
        string ans = "[";
        int index = 0;
//        int end=0,nextEnd=0;
        while (index < queue.size()) {
            TreeNode *cur = queue[index];
            if (!cur) {
                ans += "null,";
                index++;
                continue;
            }
            ans += to_string(cur->val) + ",";
            queue.emplace_back(cur->left);
            queue.emplace_back(cur->right);

            index++;
        }
        return ans.substr(0, ans.size() - 1) + "]";
    }

    vector<string> split(string s) {
        s = s.substr(1, s.size() - 2);
        string tmp = "";
        vector<string> ans;
        for (char &each: s) {
            if (each != ',') {
                tmp += each;
            } else {
                ans.emplace_back(tmp);
                tmp.clear();
            }
        }
        ans.emplace_back(tmp);
        return ans;
    }

    TreeNode *deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        vector<string> group = split(data);
        TreeNode *root = new TreeNode(stoi(group[0]));
        vector<TreeNode *> queue{root};
        int queueIndex = 0;
        int groupIndex = 1;
        TreeNode *newNode;
        while (groupIndex < group.size()) {
            TreeNode *curNode = queue[queueIndex];
            string curString = group[groupIndex];
            if (curString != "null") {
                newNode = new TreeNode(stoi(group[groupIndex]));
                curNode->left = newNode;
                queue.emplace_back(newNode);
            }
            groupIndex++;
            if (groupIndex >= group.size()) {
                break;
            }
            curString = group[groupIndex];
            if (curString != "null") {
                newNode = new TreeNode(stoi(group[groupIndex]));
                curNode->right = newNode;
                queue.emplace_back(newNode);
            }
            groupIndex++;
            queueIndex++;
        }
        return root;
    }
};

class Solution {
public:
    int targetSum;

    int dfs(TreeNode *root, int target) {
        if (!root) {
            return 0;
        }
        if (root->val == target) {
            return 1 + dfs(root->left, target) + dfs(root->right, target);
        }
        if (root->val > target) {
            return dfs(root->left, target) + dfs(root->right, target);
        }
        if (root->val < target) {
            return dfs(root->left, target) + dfs(root->right, target) + dfs(root->left, target - root->val) +
                   dfs(root->right, target - root->val);
        }
    }

    int pathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return 0;
        }
        if (root->val == targetSum) {
            return 1 +
        }
    }
};

int main() {
    TreeNode root = TreeNode(1);
    root.left = new TreeNode(2);
//    root.right=new TreeNode(3);
//    root.right->left=new TreeNode(4);
//    root.right->right=new TreeNode(5);
    Codec s;
    s.deserialize(s.serialize(&root));
}