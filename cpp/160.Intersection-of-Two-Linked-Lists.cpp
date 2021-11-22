// 97% faster
// Time complexity O(n), space complexity O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* lastA{headA};
        ListNode* lastB{headB};
        int countA{1}, countB{1};
        
        // Search for the last node
        while(lastA->next){
            lastA = lastA->next;
            countA++;
        }
        while(lastB->next){
            lastB = lastB->next;
            countB++;
        }
        // If the last node mismatch, no intersection
        if(lastA!=lastB)
            return NULL;
        // Start from the points with same length to the end
        lastA = headA;
        lastB = headB;
        while(countA>countB){
            lastA = lastA->next;
            countA--;
        }
        while(countB>countA){
            lastB = lastB->next;
            countB--;
        }
        // Find the first matching node
        while(lastA!=lastB){
            lastA = lastA->next;
            lastB = lastB->next;
        }
        return lastA;
    }
};
