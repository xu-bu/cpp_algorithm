#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 1584 Kruskal algorithm, O(m log n + mn) = O(mn)
    // as same as disjoint-set data structure, every time choose the edge with lowest weight to build a tree and ensure no circle in the process
    int minCostConnectPoints(vector <vector<int>> &points) {
        int n = points.size();
        // if an edge is in the MST now, mark it as true
        vector<bool> visit(n, false);
        struct EDGE {
            int start;
            int end;
            int dis;
        };
        vector <EDGE> edges;
        unordered_set<int> MSTnodes;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                EDGE edge = {i, j, dis};
                edges.emplace_back(edge);
            }
        }

        std::sort(edges.begin(), edges.end(),[](const EDGE & e1,const EDGE & e2){
            return e1.dis<e2.dis;
        });

        int ans = 0;

        // need to choose n-1 edges to build a MST
        for (int i = 0; i < n - 1; ++i) {
            int minVal=INT_MAX;
            int curEdge;
            for (int j = 0; j < edges.size(); ++j){
                EDGE edge=edges[j];
                // check if is visited
                if(visit[j]){
                    continue;
                }
                // check if the new edge will generate circle

                if(MSTnodes.count(edge.start)!=0 and MSTnodes.count(edge.end)!=0){
                    continue;
                }
                if(edge.dis<minVal){
                    minVal=edge.dis;
                    curEdge=j;
                }
            }
            visit[curEdge]=true;
            ans+=edges[curEdge].dis;
            // add edge into MST
            MSTnodes.emplace(edges[curEdge].start);
            MSTnodes.emplace(edges[curEdge].end);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 0, 0, 2, 4, 4, 1};
    vector<int> pop = {1, 2, 3, 4, 5};
    string s = "1210";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution solution = Solution();
    cout << solution.digitCount(s);
}