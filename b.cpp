//
// Created by test on 2022/7/2.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct cmp {
        bool operator()(pair<char, int> &a, pair<char, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };

public:
    void reconstructQueue(string input,int interval) {
        priority_queue<int,vector<int>,greater<int>> heap;
        vector<int> nums={1,5,6,3,8,9,4,2,2463,35};
        for (auto each:nums){
            heap.push(each);
        }
        for (int i=0;i<5;i++){
            cout<<heap.top()<<endl;
            heap.pop();
        }
    }
};

int main() {
    string s="124";
    char* num=const_cast<char *>(s.c_str());

    cout<<num;
}