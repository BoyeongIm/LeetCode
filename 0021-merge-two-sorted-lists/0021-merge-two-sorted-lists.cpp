class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* newHead = new ListNode();

        if (curr1->val < curr2->val) {
            newHead = curr1;
            curr1 = curr1->next;
        } else {
            newHead = curr2;
            curr2 = curr2->next;
        }

        ListNode* temp = newHead;

        while (curr1 && curr2) {
            if (curr1->val < curr2->val) {
                temp->next = curr1;
                curr1 = curr1->next;
            } else {
                temp->next = curr2;
                curr2 = curr2->next;
            }
            temp = temp->next;
        }

        if (curr1) temp->next = curr1;
        if (curr2) temp->next = curr2;

        return newHead;
    }
};