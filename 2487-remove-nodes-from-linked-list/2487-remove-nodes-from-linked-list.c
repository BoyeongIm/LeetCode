/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNodes(struct ListNode* head) {
    if (head->next==NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    struct ListNode* curr2 = prev;
    while (curr2 && curr2->next) {
        if (curr2->next->val >= curr2->val) curr2 = curr2->next;
        else {
            if (curr2->next->next) curr2->next = curr2->next->next;
            else curr2->next = NULL;
            // curr2 = curr2->next;
        }
    }

    struct ListNode* prev3 = NULL;
    struct ListNode* curr3 = prev;
    while (curr3) {
        struct ListNode* temp2 = curr3->next;
        curr3->next = prev3;
        prev3 = curr3;
        curr3 = temp2;
    }

    return prev3;
}