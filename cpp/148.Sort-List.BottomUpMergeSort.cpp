// 72% faster
// Time complexity O(nlogn), space complexity O(1)
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
		int subn{ 2 }, count{};
		ListNode *pre{ newHead }, *last{ nullptr }, *mid{ nullptr };
		p = newHead;
		while (subn < 2 * n) {
			while (p != nullptr) {
				if (count == subn) {
					last = p->next;
					merge(pre, last, mid);
					
					p = pre;
					for (int i{}; i < subn; i++) {
						p = p->next;
					}
					pre = p;
					last = nullptr;
					mid = nullptr;
					count = 0;
				}
				else if (count == subn / 2) {
					mid = p;
				}
				count++;
				p = p->next;
			}
			if (mid)
				merge(pre, last, mid);
			pre = newHead;
			p = newHead;
			last = nullptr;
			mid = nullptr;
			count = 0;
			subn *= 2;

		}
		return newHead->next;
	}
	void merge(ListNode* pre, ListNode* last, ListNode* mid) {
		if (pre->next == last || pre->next->next == last)
			return;

		ListNode *p{ pre }, *q{ mid };
		while (p != mid && q->next != last) {
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
