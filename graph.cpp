//
// Created by 64170 on 2022/9/2.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //212
    //it's OK to define these variables as global or parameter
    int rows, cols;
    bool visit[14][14];
    vector<pair<int, int>> directions{{-1, 0},
                                      {1,  0},
                                      {0,  1},
                                      {0,  -1}};
    vector<string> ans;

    //search 4 directions from board[x][y]
    void dfs(vector<vector<char>> &board, int i, int j, string path, unordered_set<string> &words) {
        if (path.size() > 10) {
            return;
        }
        if (words.count(path) != 0) {
            words.erase(path);
            ans.emplace_back(path);
        }
        for (auto &each: directions) {
            int x = i + each.first;
            int y = j + each.second;
            if (x >= 0 and x < rows and y >= 0 and y < cols and !visit[x][y]) {
                visit[x][y] = true;
                path += board[x][y];
                dfs(board, x, y, path, words);
                path.erase(path.end() - 1);
                visit[x][y] = false;
            }
        }
    }

    //the key point is that the word.size()<=10, after choose a direction, then next search only has 3 potential directions, the appropriate operations would be 4*3^10.Since u can choose every char as a start, the total operation number is about 12*12*4*3^10, which means u can just dfs to search every string less than 10-char in this matrix
    vector<string> findWords(vector<vector<char>> &_board, vector<string> &words) {
        rows = _board.size();
        cols = _board[0].size();
        unordered_set<string> set;
        for (auto &each: words) {
            set.emplace(each);
        }
        string path;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visit[i][j]) {
                    visit[i][j] = true;
                    path += _board[i][j];
                    dfs(_board, i, j, path, set);
                    path = "";
                    visit[i][j] = false;
                }
            }
        }
        return ans;
    }

    //拓扑排序
    //首先用哈希表记录每个点的入度，然后开始循环删去入度为0的点以及其相邻的边，删除的顺序即为排序。如果某一时刻不存在入度为0的点，则说明存在环
    //207 判断有无环
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        map<int, int> degrees;
        map<int, vector<int>> edges;
        for (auto &each: prerequisites) {
            degrees[each[1]]++;
            edges[each[0]].emplace_back(each[1]);
        }
        vector<int> deleteV;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                deleteV.emplace_back(i);
            }
        }
        while (!deleteV.empty()) {
            numCourses -= deleteV.size();
            vector<int> next;
            for (auto &v: deleteV) {
                for (auto &each: edges[v]) {
                    degrees[each]--;
                    if (degrees[each] == 0) {
                        next.emplace_back(each);
                    }
                }
            }
            deleteV = next;
        }
        return numCourses == 0;
    }

    //210 拓扑排序
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        map<int, vector<int>> edges;
        map<int, int> degrees;
        vector<int> deleteV;
        for (auto &each: prerequisites) {
            edges[each[1]].emplace_back(each[0]);
            degrees[each[0]]++;
        }
        vector<int> ans;
        for (int i = 0; i < numCourses; ++i) {
            if (degrees[i] == 0) {
                deleteV.emplace_back(i);
            }
        }

        while (!deleteV.empty()) {
            vector<int> next;
            numCourses -= deleteV.size();
            for (auto &v: deleteV) {
                ans.emplace_back(v);
                for (auto &each: edges[v]) {
                    degrees[each]--;
                    if (degrees[each] == 0) {
                        next.emplace_back(each);
                    }
                }
            }
            deleteV = next;
        }
        if (numCourses != 0) {
            return vector<int>{};
        }
        return ans;
    }

    // 310
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
        while (n > 2) {
            n -= deleteV.size();
            //next存储下一轮需要被删除的点
            vector<int> next;
            for (auto &v: deleteV) {
                for (auto &each: dic[v]) {
                    degrees[each]--;
                    //如果点x的入度为0，则degrees[x]是一直为0的，不可能是从别的数减下来的，无法加入next
                    //最后一轮中入度被减到1的点即为ans，如[0,1],[0,2]的情况，最后一轮时一开始degrees[0]=2，然后遍历1的时候减一下变为1，就加进去了
                    //[0,1],[1,2],[2,3]的情况同理
                    if (degrees[each] == 1) {
                        //新产生的入度为1 的点，加入等待被删除的列表
                        next.emplace_back(each);
                    }
                }
            }
            deleteV = next;
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
        if (canLink(beginWord, endWord)) {
            return 2;
        }
        vector<int> queue;
        map<int, bool> visit;
        for (int i = 0; i < n; ++i) {
            if (canLink(wordList[i], beginWord)) {
                queue.emplace_back(i);
                visit[i] = true;
            }
        }
        int curEnd = queue.size() - 1, nextEnd = queue.size() - 1;
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
                    visit[each] = true;
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

    // 2440 divide a tree into several consistent total value subtree, return max amount of subtrees u can divide.
    // Enumerate the possible value of component, the return the max edge that can be deleted.
    // assume note 0 is the root, then transform this graph into a tree. Now this problem equals to divide this tree into several subtrees and at the meanwhile ensure that each subtree's total value equals to the given component value. Return the possible max amount of subtrees.

    // node:[connected node]
    unordered_map<int, vector<int>> dic;
    vector<int> subtreeSum;
    int value;

    // Divide subtree recursively, return 0 if this subtree'total value equals value, otherwise return -1.(cannot be bool type here)
    // Now demonstrate why the type of this function must be int. When child subtree can be divided, it means this subtree equals 0 for father node. When the total value of other children equal value, then the total value is value+0, still equals value. Finally, it returns 0.

    // For an example, the root is 0 and its children are 1,2,3(weight is also the same number). Assume the required value is 3. When dfs node 3, it will return 0 and then backtrack to upper level. The value of 3 other nodes is 0+1+2=3, and for node 3, its value is 0, as a result, the total value is 0+1+2+0=3, return 0. It means value 3 is acceptable, since the total value of tree is 6, in order to let the value be 3, we need to divide tree into 2 parts, which means the max edge we can delete is 1.

    // Another point is to record the current node's father. For an example, if current node is 1 and its father is 0. Then the connected dic is 0:[1] and 1:[0], if don't record father, after dfs 0, it will dfs 1. Then when dfs 1, for each in dic[1], it will backtrack to dfs 0. The entry of this function is divide(-1,0,nums,edges), since there's no father of root, use -1 to substitute.
    int divide(int father, int child, vector<int> &nums, vector<vector<int>> &edges) {
        int total = nums[child];
        for (auto &each: dic[child]) {
            if (each != father) {// one good way to make sure u won't backtrack to father when u r traversing down
                int tmp = divide(child, each, nums, edges);
                if (tmp == -1) {
                    return -1;
                } else {
                    total += tmp;
                }
            }
        }
        if (total > value) {
            return -1;
        } else if (total == value) {
            return 0;
        } else {
            return total;
        }
    }

    int componentValue(vector<int> &nums, vector<vector<int>> &edges) {
        subtreeSum = vector<int>(nums.size());
        for (auto &each: edges) {
            dic[each[0]].emplace_back(each[1]);
            dic[each[1]].emplace_back(each[0]);
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // divide into i parts
        // O(d(sum(nums)) * nums.size()), d(n) means the amount of divisors of n. d(sum(nums)) for FOR loop and nums.size() for divide()
        for (int i = nums.size(); i >= 1; --i) {
            if (sum % i == 0) {
                value = sum / i;
                if (divide(-1, 0, nums, edges) == 0) {
                    // divide into i parts need to delete i-1 edges
                    return i - 1;
                }
            }
        }
        return -1;
    }

    //787 Bellman-Ford algorithm. This algorithm is used to calculate the shortest path from every node to a particular node in a directed graph with negative weight but with no negative cycle. Time complexity O(mn), space complexity O(n**2).
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        int edgeCount = flights.size();
        int inf = 100001;
        // matrix[v][n] means the shortest path start from v to dst within n arcs
        vector<vector<int>> matrix(n, vector<int>(edgeCount + 1, inf));
        // remember to initiate 0, it's important
        matrix[dst][0] = 0;
        for (int arcs = 1; arcs <= k + 1; ++arcs) {
            if (arcs > edgeCount) {
                if (matrix[src][edgeCount] == inf) {
                    return -1;
                }
                return matrix[src][edgeCount];
            }
            for (int v = 0; v < n; ++v) {
                matrix[v][arcs] = matrix[v][arcs - 1];
            }
            for (auto &each: flights) {
                matrix[each[0]][arcs] = min(matrix[each[0]][arcs], each[2] + matrix[each[1]][arcs - 1]);
            }
        }
        if (matrix[src][k + 1] == inf) {
            return -1;
        }
        return matrix[src][k + 1];
    }

    // 743 dijkstra, calculate the shortest path from start to each node in a graph without negative cycle, time complexity depends on the implementation of algorithm. Here is O(mlog m).
    // if negative weight exists, cannot prove the result is right
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // since we use emplace_back to build graph, we need to change node's index as start from 0
        k-=1;
        // set inf as INT_MAX/2 to prevent int overflow
        vector<int> lowCost(n,INT_MAX/2);
        // remember to set start's lowCost as 0
        lowCost[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> heap;
        // graph[start]=[end1,weight1],[end2,weight2],....
        vector<vector<pair<int,int>>> graph(n);
        for(auto &edge:times){
            graph[edge[0]-1].emplace_back(edge[1]-1,edge[2]);
        }
        // can choose arbitrary weight here, cause k will be popped out soon
        heap.emplace(0,k);
        while(!heap.empty()){
            int topNode=heap.top().second;
            heap.pop();
            for(auto &each:graph[topNode]){
                int nextNode=each.first,nextNodeWeight=each.second;
                if(lowCost[nextNode]>lowCost[topNode]+nextNodeWeight){
                    lowCost[nextNode]=lowCost[topNode]+nextNodeWeight;
                    heap.emplace(nextNodeWeight,nextNode);
                }
            }
        }
        int ans=*max_element(lowCost.begin(),lowCost.end());
        if(ans==INT_MAX/2){
            return -1;
        }
        return ans;
    }

    // 1514 variant dijkstra problem
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // use this structure to store graph
        // graph[i].second means the prob between graph[i].first and i
        vector<vector<pair<int,double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            vector<int> edge=edges[i];
            graph[edge[0]].emplace_back(edge[1],succProb[i]);
            graph[edge[1]].emplace_back(edge[0],succProb[i]);
        }
        priority_queue<pair<double,int>> heap;
        vector<double> prob(n,0);
        // don't need {} to emplace pair
        heap.emplace(1,start);
        prob[start]=1;
        while(!heap.empty()){
            auto top=heap.top();
            heap.pop();
            // each time we pop the top node from the heap then traverse all its edges. For each edge topNode->nextNode. Check if start->topNode * topNode->nextNode is lower than start->nextNode, if so, update the prob and push nextNode into heap. The weight of nextNode is the prob from start to nextNode.
            // when heap is empty, this algorithm will terminate
            for(auto &each:graph[top.second]){
                // start->topNode : prob[top.second]/top.first
                // topNode->nextNode : each.second
                // start->nextNode : prob[each.first]
                if(prob[each.first]<top.first*each.second){
                    prob[each.first]= top.first*each.second;
                    heap.emplace(prob[each.first],each.first);
                }
            }
        }
        return prob[end];
    }

     // 1584 Prim's algorithm
     // if not use heap, time complexity is O(n**2), if use minimum heap, time complexity is O((n+m)log n)
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        // if a node is in the MST now, mark it as true
        vector<bool> visit(n, false);
        vector<vector<int>> graph(n,vector<int>(n));
        // lowCost[i] means the lowest cost from MST to node i
        vector<int> lowCost(n,INT_MAX);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i][j]=graph[j][i]=dis;
            }
        }
        for (int i = 0; i < n; ++i) {
            lowCost[i]=graph[0][i];
        }
        int ans = 0;
        // start from an arbitrary node, choose 0 here
        int curNode=0;
        visit[0] = true;
        // cause the start node is already in the MST, only need to find n-1 vertices now
        for (int i = 1; i < n; ++i) {
            // in each loop, traverse all the reachable nodes in the graph, choose the one that is closest to MST to add into MST
            int minVal=INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (!visit[j] and lowCost[j]<minVal) {
                    minVal=lowCost[j];
                    curNode = j;
                }
            }
            ans += lowCost[curNode];
            visit[curNode] = true;
            // since we add a new node into MST, the distance from MST to other nodes will change
            // just traverse all the nodes that connected to new node to update lowCost
            for (int j = 0; j < n; ++j) {
                if(!visit[j]){
                    lowCost[j]=min(lowCost[j],graph[j][curNode]);
                }
            }
        }
        return ans;
    }


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
    vector<vector<int>> nums = {{1, 0}};
    vector<int> pop = {1, 2, 3, 4, 5};
    string s = "Let's take LeetCode contest";
    string p = ".*";
    Solution solution = Solution();
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    solution.findWords(board, words);
}