class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) { s1.push(l1->val); l1 = l1->next; }
        while (l2) { s2.push(l2->val); l2 = l2->next; }

        int carry = 0;
        ListNode* next = nullptr;

        while (!s1.empty() || !s2.empty() || carry) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();

            int sum = a + b + carry;
            carry = sum / 10;
            int digit = sum % 10;

            ListNode* node = new ListNode(digit);
            node->next = next;
            next = node;
        }

        return next;
    }
};