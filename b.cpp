#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        vector<int> reachNode;
        vector<int> distance;
        int start = node1;
        int dis = 0;
        while (start != -1 && !count(reachNode.begin(), reachNode.end(), start)) {
            reachNode.emplace_back(start);
            distance.emplace_back(dis);
            start = edges[start];
            dis++;
        }
        vector<int> node2Reach{};
        start = node2;
        int lastDis=0x7ffff;
        dis = 0;
        int ans=-1;
        while (start != -1 && !count(node2Reach.begin(), node2Reach.end(), start)) {
            node2Reach.emplace_back(start);
            for (int i = 0; i < reachNode.size(); ++i) {
                int curDis=max(dis,distance[i]);
                if (reachNode[i] == start&&curDis<=lastDis) {
                    if(curDis==lastDis){
                        ans=min(start,ans);
                    }else{
                        ans=start;
                    }
                    lastDis=curDis;
                }
            }
            start = edges[start];
            dis++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {5,3,1,0,2,4,5};
    string s = "ab";
    string p = ".*";
    Solution solution = Solution();
    cout << solution.closestMeetingNode(nums, 3, 2);
}