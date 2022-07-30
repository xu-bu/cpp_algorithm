struct ListNode{
    int val;
    ListNode * next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* n):val(x),next(n){}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p,*q;
        while(q!= nullptr&&q->next!= nullptr){
            q=q->next->next;
            p=p->next;
        }
        return p;
    }
};