class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;
        stack<int> to_stack;
        ListNode* curr = head;
        while (curr) {
            to_stack.push(curr->val);
            curr = curr->next;
        }

        while (!to_stack.empty()) {
            int v = to_stack.top();
            to_stack.pop();

            if (head.val == v) {
                head = head->next;
            } else return false;
        }

        return true;
    }
};