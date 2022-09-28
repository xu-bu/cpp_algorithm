//
// Created by 64170 on 2022/9/2.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //拓扑排序
    //首先用哈希表记录每个点的入度，然后开始循环删去入度为0的点以及其相邻的边，删除的顺序即为排序。如果某一时刻不存在入度为0的点，则说明存在环
    //207 判断有无环
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> degrees;
        map<int,vector<int>> edges;
        for(auto &each:prerequisites){
            degrees[each[1]]++;
            edges[each[0]].emplace_back(each[1]);
//            edges[each[1]].emplace_back(each[0]);
        }
        int n=prerequisites.size();
        vector<int> deleteV;
        for (int i = 0; i < numCourses; ++i) {
            if(degrees[i]==0){
                deleteV.emplace_back(i);
            }
        }
        while (!deleteV.empty()){
            numCourses-=deleteV.size();
            vector<int> next;
            for(auto &v:deleteV){
                for(auto &each:edges[v]){
                    degrees[each]--;
                    if(degrees[each]==0){
                        next.emplace_back(each);
                    }
                }
            }
            deleteV=next;
        }
        return numCourses==0;
    }

    //210 拓扑排序
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        map<int, vector<int>> edges;
        map<int,int> degrees;
        vector<int> deleteV;
        for(auto &each:prerequisites){
            edges[each[1]].emplace_back(each[0]);
            degrees[each[0]]++;
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if(degrees[i]==0){
                deleteV.emplace_back(i);
            }
        }

        while(!deleteV.empty()){
            vector<int> next;
            numCourses-=deleteV.size();
            for(auto &v:deleteV){
                ans.emplace_back(v);
                for(auto &each:edges[v]){
                    degrees[each]--;
                    if(degrees[each]==0){
                        next.emplace_back(each);
                    }
                }
            }
            deleteV=next;
        }
        if(numCourses!=0){
            return vector<int>{};
        }
        return ans;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        //遍历所有的边，看哪些点的入度为1，以这些点为根产生的树绝对不可能是mht，因为只要用与它相邻的点为根，然后把它自身换成叶子节点，就能产生高度更矮的树。在记录这些点后，遍历edges，删除这些点所在的边，之后重新开始计算入度，重复上诉过程，直到剩下的点的数量<=2，这些点就是答案
        set<int> verticles;
        vector<int> degrees(n);
        //记录【点：与其相邻的点】
        map<int, vector<int>> dic;
        vector<int> deleteV;
        for (int i = 0; i < edges.size(); ++i) {
            auto each = edges[i];
            degrees[each[0]]++;
            degrees[each[1]]++;
            dic[each[0]].emplace_back(each[1]);
            dic[each[1]].emplace_back(each[0]);
        }
        for (int i = 0; i < n; ++i) {
            //注意必须是<=1，如果
            if (degrees[i] <= 1) {
                deleteV.emplace_back(i);
            }
        }
        //遍历每个需要被删除的点，获取与它相邻的点，由于这个点被删除了，degrees[相邻点]--。由于本题返回的ans只会是1或2个点，故跳出条件是n>2
        while (n> 2) {
            n-=deleteV.size();
            //next存储下一轮需要被删除的点
            vector<int> next;
            for (auto &v: deleteV) {
                for (auto &each: dic[v]) {
                    degrees[each]--;
                    //如果点x的入度为0，则degrees[x]是一直为0的，不可能是从别的数减下来的，无法加入next
                    //最后一轮中入度被减到1的点即为ans，如[0,1],[0,2]的情况，最后一轮时一开始degrees[0]=2，然后遍历1的时候减一下变为1，就加进去了
                    //[0,1],[1,2],[2,3]的情况同理
                    if(degrees[each]==1){
                        //新产生的入度为1 的点，加入等待被删除的列表
                        next.emplace_back(each);
                    }
                }
            }
            deleteV=next;
        }

        return deleteV;
    }

    //127 有向图中求两个点之间最短路径长度，必须使用bfs才能保证时间复杂度最低。因为只需要求长度而不需要求路线，所以在最浅层找到终点即可，更深层就无需访问了，节省时间
    bool canLink(string s1, string s2) {
        int num = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1.at(i) != s2.at(i)) {
                num++;
            }
            if (num > 1) {
                return false;
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int n = wordList.size();
        map<int, vector<int>> dic;
        vector<vector<bool>> isLink(n, vector<bool>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (canLink(wordList[i], wordList[j])) {
                    dic[i].emplace_back(j);
                    dic[j].emplace_back(i);
                    isLink[i][j] = true;
                    isLink[j][i] = true;
                }

            }
        }
        int end = -1;
        for (int i = 0; i < n; ++i) {
            if (wordList[i] == endWord) {
                end = i;
            }
        }
        if (end == -1) {
            return 0;
        }
        if(canLink(beginWord,endWord)){
            return 2;
        }
        vector<int> queue;
        map<int, bool> visit;
        for (int i = 0; i < n; ++i) {
            if (canLink(wordList[i], beginWord)) {
                queue.emplace_back(i);
                visit[i]=true;
            }
        }
        int curEnd = queue.size()-1, nextEnd = queue.size()-1;
        int index = 0;
        int ans = 0;

        while (index < queue.size()) {
            int curWord = queue[index];
            if (isLink[curWord][end]) {
                return ans + 3;
            }
            for (auto &each: dic[curWord]) {
                if (!visit[each]) {
                    queue.emplace_back(each);
                    visit[each]=true;
                    nextEnd++;
                }
            }
            if (index == curEnd) {
                ans++;
                curEnd = nextEnd;
            }
            index++;
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> nums = {{1,0}};
    vector<int> pop = {1, 2, 3, 4, 5};
    string s = "Let's take LeetCode contest";
    string p = ".*";
    Solution solution = Solution();
    vector<vector<int>> r={{1,2},{7,3},{4,3},{5,8},{7,8},{8,2},{5,8},{3,2},{1,3},{7,6},{4,3},{7,4},{4,8},{7,3},{7,5}};
    vector<vector<int>> c={{5,7},{2,7},{4,3},{6,7},{4,3},{2,3},{6,2}};
    solution.buildMatrix(8,r,c);
}