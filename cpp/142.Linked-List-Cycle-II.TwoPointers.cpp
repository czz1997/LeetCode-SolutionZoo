// 82% faster
// O(n), O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast{head}, *slow{head};
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast)
                break;
            fast = fast->next;
            if(fast == slow)
                break;
        }
        if(!fast)
            return nullptr;
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
