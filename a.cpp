#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        double n = (double)grades.size();
        return (int)sqrt(0.25 + 2 * n) - 0.5;
    }
};

int main() {

    Solution solution = Solution();
    vector<int> nums={10,6,12,7,3,5};
//    cout << solution.findAnagrams(s,p);
    cout<<solution.maximumGroups(nums);
}