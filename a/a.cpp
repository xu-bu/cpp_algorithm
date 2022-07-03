#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        vector<vector<int>> dp;
        for (int i=0;i<n;i++){
            dp.push_back(vector<int>{});
            for (int j=0;j<2;j++){
                dp[i].push_back(0);
            }
        }
        dp[0][0]=nums[0];
        dp[0][1]=nums[0];
        for (int i=1;i<n;i++){
            if (dp[i-1][0]>0&&nums[i]>=0){

            }
            dp[i]=max(dp[i-1]*nums[i],nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums={3,6,5,7,4,8,1,0};
    Solution s=Solution();
    cout<<s.largestRectangleArea(nums);
}