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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<bool> visit(n);
        function<bool(int)> checkTree=[&](int deleteEdge){
            map<int,int> degree;
            map<int,unordered_set<int>> node2edges;
            for (int i = 0; i < n; ++i) {
                if(i!=deleteEdge){
                    degree[edges[i][0]]++;
                    degree[edges[i][1]]++;
                    node2edges[edges[i][0]].emplace(edges[i][1]);
                    node2edges[edges[i][1]].emplace(edges[i][0]);
                }
            }
            stack<int> deleteNodes;
            for(auto &each:degree){
                if(each.second==1){
                    deleteNodes.push(each.first);
                }
            }
            while(!deleteNodes.empty()){
                int node=deleteNodes.top();
                deleteNodes.pop();
                visit[node]=true;
                for(auto &each:node2edges[node]){
                    degree[each]--;
                    if(degree[each]==1){
                        deleteNodes.emplace(each);
                    }
                }
            }
            for(auto each:visit){
                if(!each){
                    return false;
                }
            }
            return true;
        };
        for (int i = n-1; i >=0; ++i) {
            if(checkTree(i)){
                return edges[i];
            }
        }
        return vector<int>{};
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


