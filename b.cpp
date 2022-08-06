#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        //以left[i][j]为右下角尝试组成矩形，存储该点及其左侧一共有多少个连续的1
        vector<vector<int>> left(rows,vector<int>(cols,0));
        for (int j = 0; j < cols; ++j) {
            for (int i = 0; i < rows; ++i) {
                if (matrix[i][j]=='1'){
                    if(j==0){
                        left[i][j]=1;
                    }else{
                        left[i][j]=left[i][j-1]+1;
                    }
                }
            }
        }
        return 1;
    }
};

int main() {
    vector<int> nums = {2,2,3,-1};
    vector<vector<char>> data={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    string s = "ab";
    string p = ".*";
    Solution solution = Solution();
    cout << solution.maximalRectangle(data);
}