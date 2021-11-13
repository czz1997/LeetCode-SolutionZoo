class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n <= 0) {
            return head;
        }
        ListNode help = head;
        int len = 0;
        while (help != null) {
            help = help.next;
            len++;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        help = dummy;
        for (int i = 1; i < len - n + 1; ++i) {
            help = help.next;
        }

        help.next = help.next.next;
        return dummy.next;
    }
}
// time complexity : faster 100% O(n)
// space complexity : faster 72.77% O(1)
