class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*p= head;
        ListNode*q= head;
        while(p&&q&&p->next)
        {
            q=q->next;
            p=p->next->next;
        }
        //cout<<q<<endl;
        return q;
    }
};