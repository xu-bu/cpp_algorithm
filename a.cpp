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
    //787 Bellman-Ford algorithm. This algorithm is used to calculate the shortest path from s to d in a directed graph with negative weight but with no negative cycle. Time complexity O(mn), space complexity O(n**2).
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
//        int rows=flights.size(),cols=flights[0].size();
        int edgeCount = flights.size();
        int inf = 100001;
        vector<vector<int>> edges(n, vector<int>(n, inf));
        // matrix[v][n] means the shortest path start from v to dst within n arcs
        vector<vector<int>> matrix(n, vector<int>(n));
        for (auto &each: flights) {
            edges[each[0]][each[1]] = each[2];
        }
        for (int arcs = 1; arcs < edgeCount; ++arcs) {
            for (int v = 0; v < n; ++v) {
                matrix[v][arcs] = matrix[v][arcs - 1];
            }
            for (auto &each: flights) {
                matrix[each[0]][arcs] = min(matrix[each[0]][arcs - 1], each[2] + matrix[each[1]][arcs - 1]);
            }
        }
        return matrix[src][edgeCount - 1];
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


