#include <bits/stdc++.h>

using namespace std;

int main() {
    //大的在堆顶,如果想要创建小根堆，在后面加greater<>
    //先看第二个元素再看第一个
//    priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
//    heap.push(pair<int, string>{1, 1});
//    heap.push(pair<int, string>{2, 1});
//    heap.push(pair<int, int>{41, 2});
//    heap.push(pair<int, int>{41, 4});

//两个不同类型的，则会先看int型
    priority_queue<pair<int, string>, vector<pair<int, string>>> heap;
    heap.push(pair<int, string>{1, "2"});
    heap.push(pair<int, string>{2, "1"});
//    priority_queue<pair<string, int>, vector<pair<string, int>>, less<>> heap;
//    heap.push(pair<string, int>{"1",1});
//    heap.push(pair<string, int>{"0",2});
    cout << heap.top().first << " " << heap.top().second;
}