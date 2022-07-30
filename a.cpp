#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //对于x,y位置，获取可填入的数有哪些
    vector<char> getNumbers(vector<vector<char>> &board, int x, int y) {
        vector<int> ret(9);
        for (int i = 0; i < 9; i++) {
            if (board[x][i] != '.') {
                ret[board[x][i] - '1'] = -1;
            }
            if (board[i][y] != '.') {
                ret[board[i][y] - '1'] = -1;
            }
        }
        //遍历九宫格，从[xStart][yStart]遍历到[xStart+2][yStart+2]
        int xStart, yStart;
        xStart = x / 3 * 3;
        yStart = y / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; ++j) {
                ret[board[xStart + i][yStart + j] - '1'] = -1;
            }
        }
        vector<char> charList;
        for (int i = 0; i < 9; ++i) {
            if(ret[i] == 0){
                charList.emplace_back('1' + i);
            }
        }
        return charList;
    }

    void dfs(vector<vector<char>> &board,int x, int y) {
        if (x == 9) {
            return;
        } else if (y == 9) {
            dfs(board,x + 1, 0);
        } else if (board[x][y] != '.') {
            dfs(board,x, y + 1);
            return;
        }
        vector<char> charList = getNumbers(board, x, y);
        for (auto &each: charList) {
            board[x][y] = each;
            dfs(board,x, y + 1);
        }
        //如果都不行，说明上一层不行，回溯上去，此时注意要把该处改回'.'
        board[x][y]='.';
    }

    void solveSudoku(vector<vector<char>> &board) {
        dfs(board,0, 0);
    }
};

int main() {
    vector<vector<char>> nums ={{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    Solution solution = Solution();
//    cout << solution.findAnagrams(s,p);
    solution.solveSudoku(nums);
}