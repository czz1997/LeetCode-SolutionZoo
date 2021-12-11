// 81% faster
// O(n), O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Count
        int n{};
        ListNode* p{head};
        while(p){
            n++;
            p = p->next;
        }
        if(n == 1)
            return true;
        // Cut second half
        p=head;
        for(int i{}; i<(n-1)/2;i++){
            p=p->next;
        }
        ListNode* halfHead{p->next};
        p->next = nullptr;
        // Reverse second half
        p = halfHead->next;
        halfHead->next = nullptr;
        while(p){
            ListNode* temp{p->next};
            p->next = halfHead;
            halfHead = p;
            p = temp;
        }
        // Compare two lists
        ListNode* q{halfHead};
        p = head;
        while(q){
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
