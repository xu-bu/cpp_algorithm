#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    //#6178 将区间分为最少组数
    int minGroups(vector<vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());
        //堆中记录每个分区的末端值，如一开始遍历到[1,5]，则堆中放一个5，代表已经使用了一个分区。此时如果再遍历到[2,6]，由于堆顶是5，比2大，说明会有重叠，必须再开一个新的分区，于是把6入堆。接下来遍历[9,16]，由于9比堆顶的5大，则把5出堆，然后把9push进去，堆中只剩下6，9。显然，堆的大小就是分区的数量。
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto &each:intervals) {
            if (!heap.empty() and each[0] > heap.top()) {
                heap.pop();
            }
            heap.push(each[1]);
        }
        return heap.size();
    }
};

int main() {
    //大的在堆顶,如果想要创建小根堆，在后面加greater<>
    //先看第二个元素再看第一个
//    priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
//    heap.push(pair<int, string>{1, 1});
//    heap.push(pair<int, string>{2, 1});
//    heap.push(pair<int, int>{41, 2});
//    heap.push(pair<int, int>{41, 4});

//两个不同类型的，则会先看int型
//    priority_queue<pair<int, string>, vector<pair<int, string>>> heap;
//    heap.push(pair<int, string>{1, "2"});
//    heap.push(pair<int, string>{2, "1"});
//    priority_queue<pair<string, int>, vector<pair<string, int>>, less<>> heap;
//    heap.push(pair<string, int>{"1",1});
//    heap.push(pair<string, int>{"0",2});
//    cout << heap.top().first << " " << heap.top().second;
    Solution s;
    vector<vector<int>> nums = {{5, 10},
                                {6, 8},
                                {1, 5},
                                {2, 3},
                                {1, 10}};
    std::sort(nums.begin(), nums.end());
    for (auto &p: nums) {
        cout << p[0] << " " << p[1]<<endl;
    }
    cout<<s.minGroups(nums);
}