#include <bits/stdc++.h>

#include <utility>

using namespace std;

class NumArray {
public:
    vector<int> tree;
    int lowbit(int x){
        return x&(-x);
    }

    //update nums[index] to nums[index]+num (index means the pos in BIT)
    void add(int index,int num){
        while(index<tree.size()){
            tree[index]+=num;
            index+= lowbit(index);
        }
    }

    //return sum of [0,right] (right means the pos in BIT)
    int presum(int right){
        int ret=0;
        while (right>=1){
            ret+=tree[right];
            right-= lowbit(right);
        }
        return ret;
    }

    NumArray(vector<int>& nums) {
        tree.emplace_back(0);//since the BIT's index starts with one, need to add an element
        for(auto &each:nums){
            tree.emplace_back(each);
        }
        //construct BIT O(n)
        for (int i = 1; i <tree.size(); ++i) {
            int j= lowbit(i)+i;
            if(j<tree.size()){
                tree[j]+=tree[i];
            }
        }
    }

    void update(int index, int val) {
        add(index+1,val- sumRange(index,index));
    }

    int sumRange(int left, int right) {
        //+1 to convert the index
        return presum(right+1)- presum(left+1-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
