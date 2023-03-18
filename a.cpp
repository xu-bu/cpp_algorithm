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
    int removeStones(vector<vector<int>>& stones) {
        int rows=stones.size(),cols=stones[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols));
        function<void(int,int)> bfs=[&](int x, int y){
            if (!visited[x][y]){
                return;
            }
            visited[x][y]=true;
            for (int i = 0; i < rows; ++i) {
                bfs(i,y);
            }
            for (int i = 0; i < cols; ++i) {
                bfs(x,i);
            }
        };
        int ans=0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j]){
                    ans++;
                    bfs(i,j);
                }
            }
        }
        return ans;
    }
};

int main() {
    string word = "103301";
    string prefix = "app";
    vector<double> nums = {0.5};
    vector<vector<int>> edges = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    Solution solution = Solution();
    cout << solution.removeStones(edges) << endl;
}


