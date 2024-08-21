class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* newHead = nullptr;

        if (list1->val < list2->val) {
            newHead = list1;
            list1 = list1->next;
        } else {
            newHead = list2;
            list2 = list2->next;
        }

        ListNode* tmp = newHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            
            tmp = tmp->next;
        }

        if (list1) tmp->next = list1;
        else tmp->next = list2;

        return newHead;
    }
};