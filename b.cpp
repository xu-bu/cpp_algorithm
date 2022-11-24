#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if(n==1){
            return 0;
        }
        vector<vector<bool>> check(n, vector<bool>(n));
        for (int center = 0; center < n; ++center) {
            for (int offset = 0; offset + center < n and center - offset >= 0; ++offset) {
                if (s.at(center + offset) == s.at(center - offset)) {
                    check[center - offset][center + offset] = true;
                }else{
                    break;
                }
            }
        }
        for (int leftCenter = 0; leftCenter < n - 1; ++leftCenter) {
            int rightCenter = leftCenter + 1;
            for (int offset = 0; offset + rightCenter < n and leftCenter - offset >= 0; ++offset) {
                int left = leftCenter - offset, right = offset + rightCenter;
                if (s.at(left) == s.at(right)) {
                    check[left][right] = true;
                }else{
                    break;
                }
            }
        }
        // ans[i] store the ans when s=s[:i]
        vector<int> ans(n+1, 2000);
        ans[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int start = 0; start <= i; ++start) {
                if (check[start][i]) {
                    if (start == 0) {
                        ans[i + 1] = 0;
                        break;
                    }
                    ans[i + 1] = min(ans[i + 1], 1 + ans[start]);
                }
            }
        }
        return ans[n];
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 0, 0, 2, 4, 4, 1};
    vector<int> pop = {1, 2, 3, 4, 5};
    string s ="cabababcbc";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution solution = Solution();
    cout << solution.minCut(s);
}