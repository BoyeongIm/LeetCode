/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct ListNode* newHead = NULL;
    if (list1->val < list2->val) {
        newHead = list1;
        list1 = list1->next;
    } else {
        newHead = list2;
        list2 = list2->next;
    }

    struct ListNode* curr = newHead;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        }
        else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1) curr->next = list1;
    else curr->next = list2;

    return newHead;
}