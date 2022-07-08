#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        vector<vector<bool>> dp(sLen+1,vector<bool>(pLen+1));

        dp[0][0] = true;
        for (int j = 2; j <= pLen; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= sLen; i++) {
            for (int j = 1; j <= pLen; j++) {
                if (s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (p[j - 2] == '.') {
                        for (int k = 0; k <= i; ++k) {
                            dp[i][j] = dp[i][j] || dp[k][j - 2];
                        }
                    } else {
                        dp[i][j] = dp[i][j - 2];
                        for (int k = i - 1;
                             k >= 0 && p[j - 2] == s[k];
                             k--) {
                            dp[i][j] = dp[i][j] || dp[k][j - 2];
                        }
                    }
                } else if (p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[sLen][pLen];
    }
};

int main() {
    vector<int> nums = {-1, -2, -9, -6};
    string s = "ab";
    string p = ".*";
    Solution solution = Solution();
    cout << solution.isMatch(s, p);
}