#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *createList(const vector<int> &nums) {
        auto *head = new ListNode();
        ListNode *p = head;
        for (auto &each: nums) {
            auto *tmp = new ListNode(each);
            p->next = tmp;
            p = p->next;
        }
        return head->next;
    }

    void traverse(ListNode *head) {
        while (head) {
            cout << head->val << "->";
            head = head->next;
        }
    }

};

int main() {
    vector<int> nums = {1};
    vector<int> tmp = {9,9};
    Solution s = Solution();
    ListNode *l1 = s.createList(nums);
    ListNode *l2 = s.createList(tmp);

    s.traverse(s.addTwoNumbers(l1, l2));
}
