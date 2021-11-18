// 97% faster
// Time complexity O(nlogn), space complexity O(logn)
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		int n{};
		ListNode* p{ head };
		while (p) {
			n++;
			p = p->next;
		}
		ListNode* newHead = new ListNode{ 0, head };
		mergeSort(newHead, nullptr, n);
		return newHead->next;
	}
	void mergeSort(ListNode* pre, ListNode* last, int n) {
		if (n <= 1)
			return;
		ListNode* midNode{ pre };
		for (int count{}; count < n / 2; count++) {
			midNode = midNode->next;
		}
		mergeSort(pre, midNode->next, n / 2);
        // recalculate midNode
		midNode = pre;
		for (int count{}; count < n / 2; count++) {
			midNode = midNode->next;
		}
		mergeSort(midNode, last, n - n / 2);
		ListNode *p{ pre }, *q{ midNode };
		while (p != midNode && q->next != last) {
			if (p->next->val < q->next->val) {
				p = p->next;
			}
			else {
				ListNode* tmp{ p->next };
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = tmp;
				p = p->next;
			}
		}
	}
};
