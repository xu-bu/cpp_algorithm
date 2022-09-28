//
// Created by 64170 on 2022/9/12.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //494 装满01背包有多少种方式
    // 尽管可以通过递归到动归的方式写出来（加sum消除负数参数），但是由于状态转移方程既有dp[j]+=dp[j-nums[i]]这种向前找的，又有dp[j]+=dp[j+nums[i]]这种向后找的，单纯反向遍历j已经不能解决新产生的dp[j]覆盖了原本的0的问题，故不能降维，所以还是得转化成01背包问题来解
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum= accumulate(nums.begin(),nums.end(),0);
        //假设nums中所有应该添负号的数的和为neg，则有sum-2*neg=target，假设有n种取法能取出这些和为neg的数，则答案为n，此时问题转换为装满neg的背包有多少种方式
        int diff=sum-target;
        if(diff%2==1 or diff<0){
            return 0;
        }
        int neg=diff/2;
        //在nums中任取，总和为j有多少种方式
        vector<int> dp(neg+1);
        dp[0]=1;
        //和二位不一样，这里要改回0了
        for (int i = 0; i < n; ++i) {
            for (int j = neg; j >=nums[i] ; --j) {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[neg];
    }

    //2400
    int numberOfWays(int startPos, int endPos, int k) {
//        k-2*neg=end-start
//                C k neg
        int diff=k-endPos+startPos;
        if(diff%2==1 or diff<0) {
            return 0;
        }
    }
};
};

int main(){
    Solution s;
    vector<int> nums={1,1,1,1,1};
    cout<<s.findTargetSumWays(nums,9);
}
