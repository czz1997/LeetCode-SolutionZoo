// 85% faster
// O(n), O(1)

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* p{head}, *q{};
        // count
        int length{};
        while(p){
            length ++;
            p = p->next;
        }
        if(length <= 2)
            return;
        // cut second half
        ListNode* halfHead{};
        p = head;
        for(int i{}; i<length / 2; i++){
            p = p->next;
        }
        halfHead = p->next;
        p->next = nullptr;
        // reverse second half
        p = halfHead ->next;
        halfHead->next = nullptr;
        while(p){
            q = p->next;
            p->next = halfHead;
            halfHead = p;
            p = q;
        }
        // insert second half into first half
        p = head;
        q = halfHead;
        while(q){
            halfHead = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = halfHead;
        }
    }
};
